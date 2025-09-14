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
        dp = [[False]*n for _ in range(n)]
        max_len = 1
        start = 0
        for i in range(n-1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j] and (j - i < 3 or dp[i+1][j-1]):
                    dp[i][j] = True
                    if j - i + 1 > max_len:
                        max_len = j - i + 1
                        start = i
        return s[start:start+max_len]
