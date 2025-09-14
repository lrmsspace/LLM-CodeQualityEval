#https://leetcode.com/problems/palindrome-partitioning-iv/
#Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​
#A string is said to be palindrome if it the same string when reversed.
# 
#Example 1:
#Input: s = "abcbdd"
#Output: true
#Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
#Example 2:
#Input: s = "bcbddxy"
#Output: false
#Explanation: s cannot be split into 3 palindromes.
# 
#Constraints:
#	3 <= s.length <= 2000
#	s​​​​​​ consists only of lowercase English letters.
class Solution(object):
    def checkPartitioning(self, s):
        """
        :type s: str
        :rtype: bool
        """
        n = len(s)
        dp = [[False for i in range(n)] for j in range(n)]
        for i in range(n):
            dp[i][i] = True
        for i in range(n-1):
            if s[i]==s[i+1]:
                dp[i][i+1] = True
        for i in range(n-2):
            if s[i]==s[i+2]:
                dp[i][i+2] = True
        for i in range(n-3):
            for j in range(i+3,n):
                if dp[i][j-1] and dp[j-1][j] and s[i]==s[j]:
                    dp[i][j] = True
        return dp[0][n-1]