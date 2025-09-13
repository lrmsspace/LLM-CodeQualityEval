#https://leetcode.com/problems/integer-break/
#Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
#Return the maximum product you can get.
# 
#Example 1:
#Input: n = 2
#Output: 1
#Explanation: 2 = 1 + 1, 1 × 1 = 1.
#Example 2:
#Input: n = 10
#Output: 36
#Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
# 
#Constraints:
#	2 <= n <= 58
class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 2:
            return 1
        if n == 3:
            return 2
            
        # Break down n into sum of 3s and handle remainder
        quotient = n // 3
        remainder = n % 3
        
        if remainder == 0:
            return 3 ** quotient
        elif remainder == 1:
            return 3 ** (quotient - 1) * 4
        else:  # remainder == 2
            return 3 ** quotient * 2    
