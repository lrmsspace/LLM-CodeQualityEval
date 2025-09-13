# You are given two strings word1 and word2.
# A string x is called valid if x can be rearranged to have word2 as a prefix.
# Return the total number of valid substrings of word1.
# Example 1:
# Input: word1 = "bcca", word2 = "abc"
# Output: 1
# Explanation:
# The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.
# Example 2:
# Input: word1 = "abcabc", word2 = "abc"
# Output: 10
# Explanation:
# All the substrings except substrings of size 1 and size 2 are valid.
# Example 3:
# Input: word1 = "abcabc", word2 = "aaabc"
# Output: 0
# Constraints:
# 1 <= word1.length <= 105
# 1 <= word2.length <= 104
# word1 and word2 consist only of lowercase English letters.

class Solution(object):
    def validSubstringCount(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        n, m = len(word1), len(word2)
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
        
        count = 0
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if dp[i][j] == m:
                    count += 1
        
        return count
        