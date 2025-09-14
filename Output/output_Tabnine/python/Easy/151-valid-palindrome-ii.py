#https://leetcode.com/problems/valid-palindrome-ii/
#Given a string s, return true if the s can be palindrome after deleting at most one character from it.
# 
#Example 1:
#Input: s = "aba"
#Output: true
#Example 2:
#Input: s = "abca"
#Output: true
#Explanation: You could delete the character 'c'.
#Example 3:
#Input: s = "abc"
#Output: false
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists of lowercase English letters.
class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        def is_palindrome(left, right):
            while left < right:
                if s[left]!= s[right]:
                    return False
                left += 1
                right -= 1
            return True
        
        n = len(s)
        for i in range(n):
            if is_palindrome(i, n - 1):
                return True
            if i > 0 and is_palindrome(i - 1, n - 1):
                return True
        
        return False
        