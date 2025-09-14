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
        MOD = 10**9 + 7
        dp = [[[0]*(maxMove+1) for _ in xrange(n)] for _ in xrange(m)]
        for k in xrange(maxMove+1):
            for i in xrange(m):
                for j in xrange(n):
                    if k == 0:
                        dp[i][j][k] = 1 if i == 0 or i == m-1 or j == 0 or j == n-1 else 0
                    else:
                        for x, y in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                            ni, nj = i+x, j+y
                            if 0 <= ni < m and 0 <= nj < n:
                                dp[i][j][k] += dp[ni][nj][k-1]
                                dp[i][j][k] %= MOD
        return sum(dp[startRow][startColumn]) % MOD
