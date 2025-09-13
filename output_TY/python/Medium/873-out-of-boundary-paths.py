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
        dp = [[0 for _ in range(n)] for _ in range(m)]
        dp[startRow][startColumn] = 1
        for i in range(maxMove):
            dp2 = [[0 for _ in range(n)] for _ in range(m)]
            for i in range(m):
                for j in range(n):
                    for x, y in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
                        if 0 <= x < m and 0 <= y < n:
                            dp2[x][y] += dp[i][j]
                        else:
                            dp2[i][j] += 1
            dp = dp2
        return sum(map(sum, dp)) % (10**9 + 7)