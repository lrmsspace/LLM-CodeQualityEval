#https://leetcode.com/problems/nth-magical-number/
#A positive integer is magical if it is divisible by either a or b.
#Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.
# 
#Example 1:
#Input: n = 1, a = 2, b = 3
#Output: 2
#Example 2:
#Input: n = 4, a = 2, b = 3
#Output: 6
# 
#Constraints:
#	1 <= n <= 109
#	2 <= a, b <= 4 * 104
class Solution(object):
    def nthMagicalNumber(self, n, a, b):
        """
        :type n: int
        :type a: int
        :type b: int
        :rtype: int
        """
        MOD = 10**9 + 7
        def gcd(x, y):
            if y == 0:
                return x
            return gcd(y, x % y)
        lcm = a * b / gcd(a, b)
        left, right = 0, n * min(a, b)
        while left < right:
            mid = (left + right) / 2
            if mid / a + mid / b - mid / lcm >= n:
                right = mid
            else:
                left = mid + 1
        return left % MOD

        