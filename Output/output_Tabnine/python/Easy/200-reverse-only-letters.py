#https://leetcode.com/problems/reverse-only-letters/
#Given a string s, reverse the string according to the following rules:
#	All the characters that are not English letters remain in the same position.
#	All the English letters (lowercase or uppercase) should be reversed.
#Return s after reversing it.
# 
#Example 1:
#Input: s = "ab-cd"
#Output: "dc-ba"
#Example 2:
#Input: s = "a-bC-dEf-ghIj"
#Output: "j-Ih-gfE-dCba"
#Example 3:
#Input: s = "Test1ng-Leet=code-Q!"
#Output: "Qedo1ct-eeLg=ntse-T!"
# 
#Constraints:
#	1 <= s.length <= 100
#	s consists of characters with ASCII values in the range [33, 122].
#	s does not contain '\"' or '\\'.
class Solution(object):
    def reverseOnlyLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Initialize two pointers, one at the start and one at the end of the string
        left, right = 0, len(s) - 1
        
        # Convert the string to a list to modify characters in-place
        s_list = list(s)
        
        while left < right:
            # Skip non-letter characters
            while left < right and not s_list[left].isalpha():
                left += 1
            while left < right and not s_list[right].isalpha():
                right -= 1
            
            # Swap the letters at the current positions
            s_list[left], s_list[right] = s_list[right], s_list[left]
            
            left += 1
            right -= 1
        
        # Convert the list back to a string and return
        return ''.join(s_list)
        