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
        if x < 0:
            sign = -1
        else:
            sign = 1
        x = abs(x)
        reversed_x = int(str(x)[::-1])
        if reversed_x > 2**31 - 1:
            return 0
        return sign * reversed_x        