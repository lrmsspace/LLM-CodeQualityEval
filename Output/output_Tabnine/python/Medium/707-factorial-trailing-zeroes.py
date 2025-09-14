#https://leetcode.com/problems/factorial-trailing-zeroes/
#Given an integer n, return the number of trailing zeroes in n!.
#Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
# 
#Example 1:
#Input: n = 3
#Output: 0
#Explanation: 3! = 6, no trailing zero.
#Example 2:
#Input: n = 5
#Output: 1
#Explanation: 5! = 120, one trailing zero.
#Example 3:
#Input: n = 0
#Output: 0
# 
#Constraints:
#	0 <= n <= 104
# 
#Follow up: Could you write a solution that works in logarithmic time complexity?
class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Using the property that a number has trailing zeroes equal to the number of times it is divisible by 10
        # We can calculate the number of times 10 appears in the prime factorization of n!
        # For each multiple of 10, there is one trailing zero
        count = 0
        while n >= 10:
            count += n // 10
            n //= 10
            
        return count
        