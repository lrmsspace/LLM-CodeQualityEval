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
            return "0"
        sign = "-" if num < 0 else ""
        num = abs(num)
        base7 = ""
        while num > 0:
            base7 = str(num % 7) + base7
            num //= 7
        return sign + base7        