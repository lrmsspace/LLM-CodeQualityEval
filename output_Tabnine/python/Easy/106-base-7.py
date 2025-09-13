#https://leetcode.com/problems/base-7/
#Given an integer num, return a string of its base 7 representation.
# 
#Example 1:
#Input: num = 100
#Output: "202"
#Example 2:
#Input: num = -7
#Output: "-10"
# 
#Constraints:
#	-107 <= num <= 107
class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return '0'
        
        is_negative = False
        if num < 0:
            is_negative = True
            num = -num
        
        result = ''
        while num > 0:
            result = str(num % 7) + result
            num //= 7
        
        if is_negative:
            result = '-' + result
        
        return result
        