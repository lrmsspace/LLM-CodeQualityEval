# You are given a string caption of length n. A good caption is a string where every character appears in groups of at least 3 consecutive occurrences.
# For example:
# "aaabbb" and "aaaaccc" are good captions.
# "aabbb" and "ccccd" are not good captions.
# You can perform the following operation any number of times:
# Choose an index i (where 0 <= i < n) and change the character at that index to either:
# The character immediately before it in the alphabet (if caption[i] != 'a').
# The character immediately after it in the alphabet (if caption[i] != 'z').
# Your task is to convert the given caption into a good caption using the minimum number of operations, and return it. If there are multiple possible good captions, return the lexicographically smallest one among them. If it is impossible to create a good caption, return an empty string "".
# Example 1:
# Input: caption = "cdcd"
# Output: "cccc"
# Explanation:
# It can be shown that the given caption cannot be transformed into a good caption with fewer than 2 operations. The possible good captions that can be created using exactly 2 operations are:
# "dddd": Change caption[0] and caption[2] to their next character 'd'.
# "cccc": Change caption[1] and caption[3] to their previous character 'c'.
# Since "cccc" is lexicographically smaller than "dddd", return "cccc".
# Example 2:
# Input: caption = "aca"
# Output: "aaa"
# Explanation:
# It can be proven that the given caption requires at least 2 operations to be transformed into a good caption. The only good caption that can be obtained with exactly 2 operations is as follows:
# Operation 1: Change caption[1] to 'b'. caption = "aba".
# Operation 2: Change caption[1] to 'a'. caption = "aaa".
# Thus, return "aaa".
# Example 3:
# Input: caption = "bc"
# Output: ""
# Explanation:
# It can be shown that the given caption cannot be converted to a good caption by using any number of operations.
# Constraints:
# 1 <= caption.length <= 5 * 104
# caption consists only of lowercase English letters.

class Solution(object):
    def minCostGoodCaption(self, caption):
        """
        :type caption: str
        :rtype: str
        """
        n = len(caption)
        dp = [[float('inf')] * 26 for _ in range(n + 1)]
        dp[n] = [0] * 26

        for i in range(n - 1, -1, -1):
            for j in range(26):
                c = chr(ord('a') + j)
                if c == caption[i]:
                    dp[i][j] = min(dp[i + 1][j] + 1, dp[i + 1][(j + 1) % 26] + 1, dp[i + 1][(j - 1) % 26] + 1)
                else:
                    dp[i][j] = min(dp[i + 1][j] + 3, dp[i + 1][(j + 1) % 26] + 1, dp[i + 1][(j - 1) % 26] + 1)

        min_cost = min(dp[0])
        result = []

        for j in range(26):
            if dp[0][j] == min_cost:
                c = chr(ord('a') + j)
                current = []
                for i in range(n):
                    if c == caption[i]:
                        current.append(c)
                    else:
                        if c == 'a':
                            current.append(chr(ord(c) + 1))
                        elif c == 'z':
                            current.append(chr(ord(c) - 1))
                        else:
                            if ord(caption[i]) - ord(c) > 0:
                                current.append(chr(ord(c) + 1))
                            else:
                                current.append(chr(ord(c) - 1))
                        c = current[-1]
                if len(result) == 0 or current < result:
                    result = current

        return ''.join(result)  
        