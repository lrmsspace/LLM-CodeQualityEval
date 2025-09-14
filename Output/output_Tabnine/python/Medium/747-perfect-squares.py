#https://leetcode.com/problems/perfect-squares/
#Given an integer n, return the least number of perfect square numbers that sum to n.
#A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
# 
#Example 1:
#Input: n = 12
#Output: 3
#Explanation: 12 = 4 + 4 + 4.
#Example 2:
#Input: n = 13
#Output: 2
#Explanation: 13 = 4 + 9.
# 
#Constraints:
#	1 <= n <= 104
class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Initialize a list dp with size n+1, where dp[i] represents the least number of perfect square numbers that sum to i
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        
        # Iterate through all possible values of i from 1 to n
        for i in range(1, n + 1):
            # Iterate through all possible perfect square numbers less than or equal to i
            for j in range(1, int(i ** 0.5) + 1):
                # Update dp[i] by taking the minimum of dp[i] and dp[i - j*j] + 1
                dp[i] = min(dp[i], dp[i - j * j] + 1)
        
        # Return the least number of perfect square numbers that sum to n
        return dp[n]
        