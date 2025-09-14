#https://leetcode.com/problems/ugly-number/
#An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.
#Given an integer n, return true if n is an ugly number.
# 
#Example 1:
#Input: n = 6
#Output: true
#Explanation: 6 = 2 × 3
#Example 2:
#Input: n = 1
#Output: true
#Explanation: 1 has no prime factors.
#Example 3:
#Input: n = 14
#Output: false
#Explanation: 14 is not ugly since it includes the prime factor 7.
# 
#Constraints:
#	-231 <= n <= 231 - 1
class Solution(object):
    def isUgly(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # Check if n is less than or equal to 0
        if n <= 0:
            return False
        
        # List of ugly factors
        ugly_factors = [2, 3, 5]
        
        # Iterate until n is reduced to 1
        while n % ugly_factors[0] == 0:
            n //= ugly_factors[0]
        while n % ugly_factors[1] == 0:
            n //= ugly_factors[1]
        while n % ugly_factors[2] == 0:
            n //= ugly_factors[2]
        
        # If n is still greater than 1, it's not an ugly number
        return n == 1
        