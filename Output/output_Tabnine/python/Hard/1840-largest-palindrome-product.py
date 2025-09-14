#https://leetcode.com/problems/largest-palindrome-product/
#Given an integer n, return the largest palindromic integer that can be represented as the product of two n-digits integers. Since the answer can be very large, return it modulo 1337.
# 
#Example 1:
#Input: n = 2
#Output: 987
#Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
#Example 2:
#Input: n = 1
#Output: 9
# 
#Constraints:
#	1 <= n <= 8
class Solution(object):
    def largestPalindrome(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Generate all possible n-digit numbers
        start = 10 ** (n - 1)
        end = 10 ** n
        
        # Find the largest palindrome
        max_palindrome = 0
        for i in range(start, end):
            for j in range(i, end):
                product = i * j
                if product > max_palindrome and str(product) == str(product)[::-1]:
                    max_palindrome = product
        
        return max_palindrome % 1337
        