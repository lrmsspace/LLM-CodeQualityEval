#https://leetcode.com/problems/count-different-palindromic-subsequences/
#Given a string s, return the number of different non-empty palindromic subsequences in s. Since the answer may be very large, return it modulo 109 + 7.
#A subsequence of a string is obtained by deleting zero or more characters from the string.
#A sequence is palindromic if it is equal to the sequence reversed.
#Two sequences a1, a2, ... and b1, b2, ... are different if there is some i for which ai != bi.
# 
#Example 1:
#Input: s = "bccb"
#Output: 6
#Explanation: The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
#Note that 'bcb' is counted only once, even though it occurs twice.
#Example 2:
#Input: s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
#Output: 104860361
#Explanation: There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 109 + 7.
# 
#Constraints:
#	1 <= s.length <= 1000
#	s[i] is either 'a', 'b', 'c', or 'd'.
class Solution(object):
    def countPalindromicSubsequences(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [[0 for i in range(n)] for j in range(n)]
        for i in range(n):
            dp[i][i] = 1
        for i in range(n-1, -1, -1):
            for j in range(i+1, n):
                if s[i] == s[j]:
                    dp[i][j] = 2 + dp[i+1][j-1]
                    for k in range(i+1, j):
                        if s[k] != s[i]:
                            dp[i][j] += dp[i][k-1] * dp[k+1][j]
                else:
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]
        return dp[0][n-1] % 1000000007