#https://leetcode.com/problems/prime-arrangements/
#Return the number of permutations of 1 to n so that prime numbers are at prime indices (1-indexed.)
#(Recall that an integer is prime if and only if it is greater than 1, and cannot be written as a product of two positive integers both smaller than it.)
#Since the answer may be large, return the answer modulo 10^9 + 7.
# 
#Example 1:
#Input: n = 5
#Output: 12
#Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.
#Example 2:
#Input: n = 100
#Output: 682289015
# 
#Constraints:
#	1 <= n <= 100
class Solution(object):
    def numPrimeArrangements(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9 + 7
        def prime(n):
            is_prime = [True] * (n + 1)
            is_prime[0] = is_prime[1] = False
            for i in range(2, int(n**0.5) + 1):
                if is_prime[i]:
                    for j in range(i*i, n + 1, i):
                        is_prime[j] = False
            return sum(is_prime)

        n_primes = prime(n)
        return (math.factorial(n_primes) * math.factorial(n - n_primes)) % MOD
