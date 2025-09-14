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
        if len(s) < 2:
            return s
        start, end = 0, 0
        for i in range(len(s)):
            len1 = self.expandAroundCenter(s, i, i)
            len2 = self.expandAroundCenter(s, i, i + 1)
            max_len = max(len1, len2)
            if max_len > end - start:
                start = i - (max_len - 1) // 2
                end = i + max_len // 2
        return s[start:end + 1]        