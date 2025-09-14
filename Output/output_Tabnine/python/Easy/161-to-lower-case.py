#https://leetcode.com/problems/to-lower-case/
#Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.
# 
#Example 1:
#Input: s = "Hello"
#Output: "hello"
#Example 2:
#Input: s = "here"
#Output: "here"
#Example 3:
#Input: s = "LOVELY"
#Output: "lovely"
# 
#Constraints:
#	1 <= s.length <= 100
#	s consists of printable ASCII characters.
class Solution(object):
    def toLowerCase(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Use list comprehension to iterate over each character in the string
        # If the character is uppercase, convert it to lowercase using the lower() method
        # Otherwise, keep it as is
        return ''.join(char.lower() if char.isupper() else char for char in s)
        