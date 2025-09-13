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
        reversed_num = 0
        negative = x < 0
        x = abs(x)
        
        while x != 0:
            digit = x % 10
            x //= 10
            
            if (reversed_num > 214748364 or 
               (reversed_num == 214748364 and digit > 7)):
                return 0
            
            reversed_num = reversed_num * 10 + digit
        
        return -reversed_num if negative else reversed_num

