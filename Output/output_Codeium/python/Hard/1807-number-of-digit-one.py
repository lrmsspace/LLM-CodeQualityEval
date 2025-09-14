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
        res = 0
        for i in range(1, len(str(n)) + 1):
            res += (n // (10 ** i)) * (10 ** (i - 1)) + min(max(n % (10 ** i) - 10 ** (i - 1) + 1, 0), 10 ** (i - 1))
        return res
