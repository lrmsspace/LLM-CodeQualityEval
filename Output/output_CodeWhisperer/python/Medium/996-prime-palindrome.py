#https://leetcode.com/problems/prime-palindrome/
#Given an integer n, return the smallest prime palindrome greater than or equal to n.
#An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.
#	For example, 2, 3, 5, 7, 11, and 13 are all primes.
#An integer is a palindrome if it reads the same from left to right as it does from right to left.
#	For example, 101 and 12321 are palindromes.
#The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].
# 
#Example 1:
#Input: n = 6
#Output: 7
#Example 2:
#Input: n = 8
#Output: 11
#Example 3:
#Input: n = 13
#Output: 101
# 
#Constraints:
#	1 <= n <= 108
class Solution(object):
    def primePalindrome(self, n):
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
        
        def is_palindrome(num):
            return str(num) == str(num)[::-1]
        
        while True:
            if n <= 2:
                return 2
            if n % 2 == 0:
                n += 1
            if is_palindrome(n) and is_prime(n):
                return n
            n += 1
            while not is_palindrome(n):
                n += 1
        