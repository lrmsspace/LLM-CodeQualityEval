#https://leetcode.com/problems/reordered-power-of-2/
#You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
#Return true if and only if we can do this so that the resulting number is a power of two.
# 
#Example 1:
#Input: n = 1
#Output: true
#Example 2:
#Input: n = 10
#Output: false
# 
#Constraints:
#	1 <= n <= 109
class Solution(object):
    def reorderedPowerOf2(self, n):
        """
        :type n: int
        :rtype: bool
        """
        def count(n):
            return sorted([int(i) for i in str(n)])
        def check(n):
            return count(n) == count(2**i)
        for i in range(30):
            if check(n):
                return True
        return False