#https://leetcode.com/problems/count-primes/
#Given an integer n, return the number of prime numbers that are strictly less than n.
# 
#Example 1:
#Input: n = 10
#Output: 4
#Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
#Example 2:
#Input: n = 0
#Output: 0
#Example 3:
#Input: n = 1
#Output: 0
# 
#Constraints:
#	0 <= n <= 5 * 106
class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        def is_prime(num):
            if num < 2:
                return False
            for i in range(2, int(num**0.5) + 1):
                if num % i == 0:
                    return False
            return True
        
        count = 0
        for i in range(2, n):
            if is_prime(i):
                count += 1
        return count
        