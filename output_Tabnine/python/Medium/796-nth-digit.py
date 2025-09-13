#https://leetcode.com/problems/nth-digit/
#Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
# 
#Example 1:
#Input: n = 3
#Output: 3
#Example 2:
#Input: n = 11
#Output: 0
#Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
# 
#Constraints:
#	1 <= n <= 231 - 1
class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Find the digit place
        place = 1
        while n > 9 * (10 ** (place - 1)):
            n -= 9 * (10 ** (place - 1))
            place += 1
        
        # Determine the digit
        digit = (n - 1) // place + 1
        if digit == 10:
            return 0
        else:
            return int(str(10 ** (place - 1)) + str(digit)[-1])
        
        