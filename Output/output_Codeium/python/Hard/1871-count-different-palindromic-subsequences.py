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
        MOD = 10**9 + 7
        n = len(s)
        dp = [[[0]*2 for _ in range(4)] for _ in range(n)]
        dp[0][0][ord(s[0]) - ord('a')] = 1
        for i in range(1, n):
            for j in range(i, -1, -1):
                for k in range(4):
                    dp[i][j][k] += dp[i-1][j][k]
                    if j > 0:
                        dp[i][j-1][k] += dp[i-1][j][k]
                    if i > 0 and ord(s[i]) == ord(s[j-1]):
                        dp[i][j-1][k] += dp[i-1][j-1][k]
                    dp[i][j][k] %= MOD
        return sum(sum(row) for row in dp[-1]) - (1 if n % 2 == 0 else 0)
