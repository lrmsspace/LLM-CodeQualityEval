#https://leetcode.com/problems/next-greater-element-iii/
#Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
#Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
# 
#Example 1:
#Input: n = 12
#Output: 21
#Example 2:
#Input: n = 21
#Output: -1
# 
#Constraints:
#	1 <= n <= 231 - 1
class Solution(object):
    def nextGreaterElement(self, n):
        """
        :type n: int
        :rtype: int
        """
        n = list(str(n))
        i = len(n) - 1
        while i > 0 and n[i - 1] >= n[i]:
            i -= 1
        if i == 0:
            return -1
        j = len(n) - 1
        while n[j] <= n[i - 1]:
            j -= 1
        n[i - 1], n[j] = n[j], n[i - 1]
        n[i:] = reversed(n[i:])
        result = int(''.join(n))
        return result if result < 2 ** 31 else -1        