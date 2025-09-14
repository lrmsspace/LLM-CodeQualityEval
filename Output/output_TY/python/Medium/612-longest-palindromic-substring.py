#https://leetcode.com/problems/longest-palindromic-substring/
#Given a string s, return the longest palindromic substring in s.
# 
#Example 1:
#Input: s = "babad"
#Output: "bab"
#Explanation: "aba" is also a valid answer.
#Example 2:
#Input: s = "cbbd"
#Output: "bb"
# 
#Constraints:
#	1 <= s.length <= 1000
#	s consist of only digits and English letters.
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        dp = [[False for i in range(n)] for j in range(n)]
        max_len = 1
        start = 0
        for i in range(n):
            dp[i][i] = True
        for i in range(n-1):
            if s[i] == s[i+1]:
                dp[i][i+1] = True
                max_len = 2
                start = i
        for k in range(3, n+1):
            for i in range(n-k+1):
                j = i+k-1
                if s[i] == s[j] and dp[i+1][j-1]:
                    dp[i][j] = True
                    max_len = k
                    start = i
        
        return s[start:start+max_len]
