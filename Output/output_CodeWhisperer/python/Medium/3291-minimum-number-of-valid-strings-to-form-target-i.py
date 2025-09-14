# You are given an array of strings words and a string target.
# A string x is called valid if x is a prefix of any string in words.
# Return the minimum number of valid strings that can be concatenated to form target. If it is not possible to form target, return -1.
# Example 1:
# Input: words = ["abc","aaaaa","bcdef"], target = "aabcdabc"
# Output: 3
# Explanation:
# The target string can be formed by concatenating:
# Prefix of length 2 of words[1], i.e. "aa".
# Prefix of length 3 of words[2], i.e. "bcd".
# Prefix of length 3 of words[0], i.e. "abc".
# Example 2:
# Input: words = ["abababab","ab"], target = "ababaababa"
# Output: 2
# Explanation:
# The target string can be formed by concatenating:
# Prefix of length 5 of words[0], i.e. "ababa".
# Prefix of length 5 of words[0], i.e. "ababa".
# Example 3:
# Input: words = ["abcdef"], target = "xyz"
# Output: -1
# Constraints:
# 1 <= words.length <= 100
# 1 <= words[i].length <= 5 * 103
# The input is generated such that sum(words[i].length) <= 105.
# words[i] consists only of lowercase English letters.
# 1 <= target.length <= 5 * 103
# target consists only of lowercase English letters.

class Solution(object):
    def minValidStrings(self, words, target):
        """
        :type words: List[str]
        :type target: str
        :rtype: int
        """
        # dp[i] represents the minimum number of valid strings that can be formed using the first i words
        dp = [-1] * (len(target) + 1)
        dp[0] = 0

        for i in range(1, len(target) + 1):
            for word in words:
                if i >= len(word) and target[i - len(word):i] == word:
                    if dp[i - len(word)] != -1:
                        if dp[i] == -1:
                            dp[i] = dp[i - len(word)] + 1
                        else:
                            dp[i] = min(dp[i], dp[i - len(word)] + 1)

        return dp[-1]        