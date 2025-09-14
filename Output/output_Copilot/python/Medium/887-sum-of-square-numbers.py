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
        if c < 0:
            return False
        if c == 0:
            return True
        left = 0
        right = int(c ** 0.5)
        while left <= right:
            sum_of_squares = left * left + right * right
            if sum_of_squares == c:
                return True
            elif sum_of_squares < c:
                left += 1
            else:
                right -= 1
        return False        