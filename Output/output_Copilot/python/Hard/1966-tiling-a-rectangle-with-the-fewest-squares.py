#https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/
#Given a rectangle of size n x m, return the minimum number of integer-sided squares that tile the rectangle.
# 
#Example 1:
#Input: n = 2, m = 3
#Output: 3
#Explanation: 3 squares are necessary to cover the rectangle.
#2 (squares of 1x1)
#1 (square of 2x2)
#Example 2:
#Input: n = 5, m = 8
#Output: 5
#Example 3:
#Input: n = 11, m = 13
#Output: 6
# 
#Constraints:
#	1 <= n, m <= 13
class Solution(object):
    def tilingRectangle(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        dp = [[float('inf')] * (m + 1) for _ in range(n + 1)]
        dp[0][0] = 0

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                for k in range(1, min(i, j) + 1):
                    dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j - k] + 1)

        return dp[n][m]        