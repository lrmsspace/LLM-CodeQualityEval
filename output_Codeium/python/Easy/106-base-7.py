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
        res = ""
        n = abs(num)
        while n > 0:
            res = str(n % 7) + res
            n //= 7
        return res if num > 0 else "-" + res
