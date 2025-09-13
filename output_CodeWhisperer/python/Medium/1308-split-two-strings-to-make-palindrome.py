#https://leetcode.com/problems/split-two-strings-to-make-palindrome/
#You are given two strings a and b of the same length. Choose an index and split both strings at the same index, splitting a into two strings: aprefix and asuffix where a = aprefix + asuffix, and splitting b into two strings: bprefix and bsuffix where b = bprefix + bsuffix. Check if aprefix + bsuffix or bprefix + asuffix forms a palindrome.
#When you split a string s into sprefix and ssuffix, either ssuffix or sprefix is allowed to be empty. For example, if s = "abc", then "" + "abc", "a" + "bc", "ab" + "c" , and "abc" + "" are valid splits.
#Return true if it is possible to form a palindrome string, otherwise return false.
#Notice that x + y denotes the concatenation of strings x and y.
# 
#Example 1:
#Input: a = "x", b = "y"
#Output: true
#Explaination: If either a or b are palindromes the answer is true since you can split in the following way:
#aprefix = "", asuffix = "x"
#bprefix = "", bsuffix = "y"
#Then, aprefix + bsuffix = "" + "y" = "y", which is a palindrome.
#Example 2:
#Input: a = "xbdef", b = "xecab"
#Output: false
#Example 3:
#Input: a = "ulacfd", b = "jizalu"
#Output: true
#Explaination: Split them at index 3:
#aprefix = "ula", asuffix = "cfd"
#bprefix = "jiz", bsuffix = "alu"
#Then, aprefix + bsuffix = "ula" + "alu" = "ulaalu", which is a palindrome.
# 
#Constraints:
#	1 <= a.length, b.length <= 105
#	a.length == b.length
#	a and b consist of lowercase English letters
class Solution(object):
    def checkPalindromeFormation(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: bool
        """
        def check_palindrome(s, left, right):
            while left < right and s[left] == s[right]:
                left += 1
                right -= 1
            return left >= right
        
        def can_form_palindrome(s1, s2):
            left, right = 0, len(s1) - 1
            
            # Check prefix of s1 with suffix of s2
            while left < right and s1[left] == s2[right]:
                left += 1
                right -= 1
            
            # If we reached the middle or if remaining parts are palindromes
            if left >= right:
                return True
                
            # Check if the remaining middle parts are palindromes
            return (check_palindrome(s1, left, right) or 
                   check_palindrome(s2, left, right))
        
        # Try both combinations: a+b and b+a
        return can_form_palindrome(a, b) or can_form_palindrome(b, a)
    