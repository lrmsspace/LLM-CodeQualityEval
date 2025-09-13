#https://leetcode.com/problems/power-of-four/
#Given an integer n, return true if it is a power of four. Otherwise, return false.
#An integer n is a power of four, if there exists an integer x such that n == 4x.
# 
#Example 1:
#Input: n = 16
#Output: true
#Example 2:
#Input: n = 5
#Output: false
#Example 3:
#Input: n = 1
#Output: true
# 
#Constraints:
#	-231 <= n <= 231 - 1
# 
#Follow up: Could you solve it without loops/recursion?
class Solution(object):
    def isPowerOfFour(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # If n is less than or equal to 0, it's not a power of 4
        if n <= 0:
            return False
        
        # Check if n is a power of 4 by checking if it is a power of 2 and if the number of 1s in its binary representation is even
        return n & (n - 1) == 0 and bin(n).count('1') % 2 == 0
        