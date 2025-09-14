#https://leetcode.com/problems/strange-printer/
#There is a strange printer with the following two special properties:
#	The printer can only print a sequence of the same character each time.
#	At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
#Given a string s, return the minimum number of turns the printer needed to print it.
# 
#Example 1:
#Input: s = "aaabbb"
#Output: 2
#Explanation: Print "aaa" first and then print "bbb".
#Example 2:
#Input: s = "aba"
#Output: 2
#Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
# 
#Constraints:
#	1 <= s.length <= 100
#	s consists of lowercase English letters.
class Solution(object):
    def strangePrinter(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        if n == 0:
            return 0
        dp = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            dp[i][i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    dp[i][j] = dp[i][j - 1]
                else:
                    min_val = float('inf')
                    for k in range(i, j):
                        min_val = min(min_val, dp[i][k] + dp[k + 1][j])
                    dp[i][j] = min_val
        return dp[0][n - 1]
        