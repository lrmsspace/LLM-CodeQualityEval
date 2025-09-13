#https://leetcode.com/problems/ugly-number-iii/
#An ugly number is a positive integer that is divisible by a, b, or c.
#Given four integers n, a, b, and c, return the nth ugly number.
# 
#Example 1:
#Input: n = 3, a = 2, b = 3, c = 5
#Output: 4
#Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
#Example 2:
#Input: n = 4, a = 2, b = 3, c = 4
#Output: 6
#Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
#Example 3:
#Input: n = 5, a = 2, b = 11, c = 13
#Output: 10
#Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
# 
#Constraints:
#	1 <= n, a, b, c <= 109
#	1 <= a * b * c <= 1018
#	It is guaranteed that the result will be in range [1, 2 * 109].
class Solution(object):
    def nthUglyNumber(self, n, a, b, c):
        """
        :type n: int
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """
        def gcd(x, y):
            if x == 0:
                return y
            return gcd(y % x, x)

        lcm = lambda x, y: x * y // gcd(x, y)

        ab = lcm(a, b)
        bc = lcm(b, c)
        ac = lcm(a, c)
        abc = lcm(ab, c)
        res = 0
        x, y, z, m = 0, 0, 0, 0
        for _ in range(n):
            v1, v2, v3, v4 = a * x, b * y, c * z, abc * m
            res = min(v1, v2, v3, v4)
            if res == v1:
                x += 1
            if res == v2:
                y += 1
            if res == v3:
                z += 1
            if res == v4:
                m += 1
        return res
