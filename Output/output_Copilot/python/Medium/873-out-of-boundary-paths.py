#https://leetcode.com/problems/out-of-boundary-paths/
#There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
#Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.
# 
#Example 1:
#Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
#Output: 6
#Example 2:
#Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
#Output: 12
# 
#Constraints:
#	1 <= m, n <= 50
#	0 <= maxMove <= 50
#	0 <= startRow < m
#	0 <= startColumn < n
class Solution(object):
    def findPaths(self, m, n, maxMove, startRow, startColumn):
        """
        :type m: int
        :type n: int
        :type maxMove: int
        :type startRow: int
        :type startColumn: int
        :rtype: int
        """
        dp = [[[0] * n for _ in range(m)] for _ in range(maxMove + 1)]
        dp[0][startRow][startColumn] = 1
        mod = 10**9 + 7
        
        for move in range(1, maxMove + 1):
            for row in range(m):
                for col in range(n):
                    dp[move][row][col] = (dp[move - 1][row - 1][col] if row > 0 else 0) + \
                                        (dp[move - 1][row + 1][col] if row < m - 1 else 0) + \
                                        (dp[move - 1][row][col - 1] if col > 0 else 0) + \
                                        (dp[move - 1][row][col + 1] if col < n - 1 else 0)
                    dp[move][row][col] %= mod
        
        result = sum(dp[maxMove][i][j] for i in range(m) for j in range(n)) % mod
        return result        