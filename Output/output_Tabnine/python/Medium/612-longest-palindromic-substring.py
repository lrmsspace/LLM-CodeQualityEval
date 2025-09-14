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
        # Initialize the result as an empty string
        result = ""
        
        # Iterate through each character in the string
        for i in range(len(s)):
            # Check for odd-length palindromes centered at i
            odd_length = self.expand_around_center(s, i, i)
            
            # Check for even-length palindromes centered at i and i+1
            even_length = self.expand_around_center(s, i, i+1)
            
            # Update the result if the current palindrome is longer
            result = max(result, odd_length, even_length, key=len)
        
        return result
        