#https://leetcode.com/problems/longest-palindromic-subsequence/
#Given a string s, find the longest palindromic subsequence's length in s.
#A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
# 
#Example 1:
#Input: s = "bbbab"
#Output: 4
#Explanation: One possible longest palindromic subsequence is "bbbb".
#Example 2:
#Input: s = "cbbd"
#Output: 2
#Explanation: One possible longest palindromic subsequence is "bb".
# 
#Constraints:
#	1 <= s.length <= 1000
#	s consists only of lowercase English letters.
class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [[0] * n for _ in range(n)]

        # 每个字符本身都是一个回文子序列
        for i in range(n):
            dp[i][i] = 1

        # 从后往前遍历字符串
        for length in range(2, n + 1):     # 子序列的长度
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        return dp[0][n - 1]   