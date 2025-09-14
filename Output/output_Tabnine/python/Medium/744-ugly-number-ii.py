#https://leetcode.com/problems/ugly-number-ii/
#An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
#Given an integer n, return the nth ugly number.
# 
#Example 1:
#Input: n = 10
#Output: 12
#Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
#Example 2:
#Input: n = 1
#Output: 1
#Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
# 
#Constraints:
#	1 <= n <= 1690
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        ugly = [0] * n
        ugly[0] = 1
        i2, i3, i5 = 0, 0, 0
        for i in range(1, n):
            ugly[i] = min(ugly[i2] * 2, ugly[i3] * 3, ugly[i5] * 5)
            if ugly[i] == ugly[i2] * 2:
                i2 += 1
            if ugly[i] == ugly[i3] * 3:
                i3 += 1
            if ugly[i] == ugly[i5] * 5:
                i5 += 1
        return ugly[-1]
        