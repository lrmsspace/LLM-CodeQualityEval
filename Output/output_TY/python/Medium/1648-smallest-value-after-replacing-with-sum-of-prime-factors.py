#https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/
#You are given a positive integer n.
#Continuously replace n with the sum of its prime factors.
#	Note that if a prime factor divides n multiple times, it should be included in the sum as many times as it divides n.
#Return the smallest value n will take on.
# 
#Example 1:
#Input: n = 15
#Output: 5
#Explanation: Initially, n = 15.
#15 = 3 * 5, so replace n with 3 + 5 = 8.
#8 = 2 * 2 * 2, so replace n with 2 + 2 + 2 = 6.
#6 = 2 * 3, so replace n with 2 + 3 = 5.
#5 is the smallest value n will take on.
#Example 2:
#Input: n = 3
#Output: 3
#Explanation: Initially, n = 3.
#3 is the smallest value n will take on.
# 
#Constraints:
#	2 <= n <= 105
class Solution(object):
    def smallestValue(self, n):
        """
        :type n: int
        :rtype: int
        """
        def prime_factors(n):
            i = 2
            factors = []
            while i * i <= n:
                if n % i:
                    i += 1
                else:
                    n //= i
                    factors.append(i)
            if n > 1:
                factors.append(n)
            return factors
        
        factors = prime_factors(n)
        while True:
            n = sum(factors)
            if n == sum(prime_factors(n)):
                return n
            factors = prime_factors(n)
        return n