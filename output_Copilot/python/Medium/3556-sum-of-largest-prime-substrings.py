# Given a string s, find the sum of the 3 largest unique prime numbers that can be formed using any of its substrings.
# Return the sum of the three largest unique prime numbers that can be formed. If fewer than three exist, return the sum of all available primes. If no prime numbers can be formed, return 0.
# Note: Each prime number should be counted only once, even if it appears in multiple substrings. Additionally, when converting a substring to an integer, any leading zeros are ignored.
# Example 1:
# Input: s = "12234"
# Output: 1469
# Explanation:
# The unique prime numbers formed from the substrings of "12234" are 2, 3, 23, 223, and 1223.
# The 3 largest primes are 1223, 223, and 23. Their sum is 1469.
# Example 2:
# Input: s = "111"
# Output: 11
# Explanation:
# The unique prime number formed from the substrings of "111" is 11.
# Since there is only one prime number, the sum is 11.
# Constraints:
# 1 <= s.length <= 10
# s consists of only digits.

class Solution(object):
    def sumOfLargestPrimes(self, s):
        """
        :type s: str
        :rtype: int
        """
        from itertools import combinations
        from sympy import isprime

        unique_primes = set()

        # Generate all substrings of s
        for i in range(len(s)):
            for j in range(i + 1, len(s) + 1):
                substring = s[i:j]
                if substring[0] != '0':
                    num = int(substring)
                    if isprime(num):
                        unique_primes.add(num)
        # Sort the unique primes in descending order
        sorted_primes = sorted(unique_primes, reverse=True)
        # Take the top 3 largest primes
        largest_primes = sorted_primes[:3]
        # Return the sum of the largest primes
        return sum(largest_primes)
            