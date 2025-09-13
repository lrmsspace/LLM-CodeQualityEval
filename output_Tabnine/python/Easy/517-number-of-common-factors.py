#https://leetcode.com/problems/number-of-common-factors/
#Given two positive integers a and b, return the number of common factors of a and b.
#An integer x is a common factor of a and b if x divides both a and b.
# 
#Example 1:
#Input: a = 12, b = 6
#Output: 4
#Explanation: The common factors of 12 and 6 are 1, 2, 3, 6.
#Example 2:
#Input: a = 25, b = 30
#Output: 2
#Explanation: The common factors of 25 and 30 are 1, 5.
# 
#Constraints:
#	1 <= a, b <= 1000
class Solution(object):
    def commonFactors(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        # Calculate the Greatest Common Divisor (GCD) of a and b
        def gcd(x, y):
            while y:
                x, y = y, x % y
            return x
        
        # Find the common factors by counting from 1 to the smaller number
        return sum(1 for i in range(1, min(a, b) + 1) if gcd(i, a) == gcd(i, b))
        