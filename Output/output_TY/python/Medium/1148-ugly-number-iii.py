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
            if y == 0:
                return x
            else:
                return gcd(y, x % y)
        a, b, c = sorted([a, b, c])
        g = gcd(a, b)
        g = gcd(g, c)
        a, b, c = a // g, b // g, c // g
        a, b, c = sorted([a, b, c])
        l = min(a, b, c)
        r = max(a, b, c) * n
        while l < r:
            mid = (l + r) // 2
            if mid // a + mid // b + mid // c - mid // (a * b // g) - mid // (b * c // g) - mid // (a * c // g) + mid // (a * b * c // g ** 3) >= n:
                r = mid
            else:
                l = mid + 1
        return l        
    
