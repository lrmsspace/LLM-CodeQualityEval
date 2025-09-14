#https://leetcode.com/problems/sum-of-square-numbers/
#Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
# 
#Example 1:
#Input: c = 5
#Output: true
#Explanation: 1 * 1 + 2 * 2 = 5
#Example 2:
#Input: c = 3
#Output: false
# 
#Constraints:
#	0 <= c <= 231 - 1
class Solution(object):
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        # Binary search for potential squares of integers
        low, high = 0, int(c ** 0.5)
        while low <= high:
            square = low * low + high * high
            if square == c:
                return True
            elif square < c:
                low += 1
            else:
                high -= 1
        return False
        