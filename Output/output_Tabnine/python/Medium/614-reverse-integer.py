#https://leetcode.com/problems/reverse-integer/
#Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
#Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
# 
#Example 1:
#Input: x = 123
#Output: 321
#Example 2:
#Input: x = -123
#Output: -321
#Example 3:
#Input: x = 120
#Output: 21
# 
#Constraints:
#	-231 <= x <= 231 - 1
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        # Convert the integer to a string to reverse it
        str_x = str(x)
        
        # If the integer is negative, remove the negative sign and reverse the string
        if str_x[0] == '-':
            reversed_str = '-' + str_x[:0:-1]
        else:
            reversed_str = str_x[::-1]
        
        # Convert the reversed string back to an integer
        reversed_int = int(reversed_str)
        
        # Check if the reversed integer is within the 32-bit integer range
        if reversed_int < -2**31 or reversed_int > 2**31 - 1:
            return 0
        
        return reversed_int
        