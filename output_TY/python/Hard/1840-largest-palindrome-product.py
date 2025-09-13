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
        if n == 1: return 9
        for i in range(10**(n-1), 10**n):
            j = int(str(i)[::-1])
            k = 10**n - i
            if i*j > 10**(2*n-1): break
            if i*i < 10**(2*n-1): continue
            if i*j
        return 1337 - i*j