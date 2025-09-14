#https://leetcode.com/problems/number-of-digit-one/
#Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
# 
#Example 1:
#Input: n = 13
#Output: 6
#Example 2:
#Input: n = 0
#Output: 0
# 
#Constraints:
#	0 <= n <= 109
class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        ones, m = 0, 1
        while m <= n:
            ones += (n // (m * 10)) * m + min(max(n % (m * 10) - m + 1, 0), m)
            m *= 10
        return ones