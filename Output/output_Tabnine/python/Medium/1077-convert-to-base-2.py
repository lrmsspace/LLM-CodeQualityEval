#https://leetcode.com/problems/convert-to-base-2/
#Given an integer n, return a binary string representing its representation in base -2.
#Note that the returned string should not have leading zeros unless the string is "0".
# 
#Example 1:
#Input: n = 2
#Output: "110"
#Explantion: (-2)2 + (-2)1 = 2
#Example 2:
#Input: n = 3
#Output: "111"
#Explantion: (-2)2 + (-2)1 + (-2)0 = 3
#Example 3:
#Input: n = 4
#Output: "100"
#Explantion: (-2)2 = 4
# 
#Constraints:
#	0 <= n <= 109
class Solution(object):
    def baseNeg2(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 0:
            return "0"
        
        is_negative = n < 0
        n = abs(n)
        
        binary = ""
        
        while n > 0:
            binary = str(n % 2) + binary
            n //= 2
        
        if is_negative:
            binary = "-" + binary
        
        return binary
        