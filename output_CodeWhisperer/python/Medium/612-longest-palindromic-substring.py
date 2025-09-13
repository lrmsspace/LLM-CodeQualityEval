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
        if not s:
            return ""
        if len(s) == 1:
            return s
        max_len = 0
        max_str = ""
        for i in range(len(s)):
            for j in range(i+1, len(s)+1):
                if s[i:j] == s[i:j][::-1]:
                    if j-i > max_len:
                        max_len = j-i
                        max_str = s[i:j]
        return max_str

        