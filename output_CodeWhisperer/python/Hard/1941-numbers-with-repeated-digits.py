#https://leetcode.com/problems/numbers-with-repeated-digits/
#Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.
# 
#Example 1:
#Input: n = 20
#Output: 1
#Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
#Example 2:
#Input: n = 100
#Output: 10
#Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
#Example 3:
#Input: n = 1000
#Output: 262
# 
#Constraints:
#	1 <= n <= 109
class Solution(object):
    def numDupDigitsAtMostN(self, n):
        """
        :type n: int
        :rtype: int
        """

        def f(n):
            if n <= 1:
                return 1
            return 9 * A(9, n - 1) + f(n - 1)

        def A(m, n):
            return 1 if n == 0 else m * A(m - 1, n - 1) + f(n)

        L = list(map(int, str(n + 1)))
        res = 0
        for i in range(1, len(L)):
            res += 9 * A(9, i - 1)
        s = set()
        for i, v in enumerate(L):
            for y in range(0 if i else 1, v):
                if y not in s:
                    res += A(9 - i, len(L) - i - 1)
            if v in s:
                break
            s.add(v)
        return n - res
