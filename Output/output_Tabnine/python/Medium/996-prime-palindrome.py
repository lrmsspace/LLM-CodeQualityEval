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
        # Function to check if a number is prime
        def is_prime(num):
            if num < 2:
                return False
            for i in range(2, int(num**0.5) + 1):
                if num % i == 0:
                    return False
            return True
        
        # Function to generate a palindrome
        def generate_palindrome(num):
            # Convert the number to a string
            num_str = str(num)
            # Reverse the string
            reversed_str = num_str[::-1]
            # Append the reversed string to the original number
            return int(num_str + reversed_str)
        
        # Find the smallest prime palindrome greater than or equal to n
        while True:
            palindrome = generate_palindrome(n)
            if is_prime(palindrome):
                return palindrome
            n += 1
        
        
        