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
        
        # dp[moves][row][col] represents number of ways to reach (row,col) with k moves
        dp = [[0] * n for _ in range(m)]
        dp[startRow][startColumn] = 1
        
        count = 0
        
        # For each move
        for moves in range(maxMove):
            temp = [[0] * n for _ in range(m)]
            
            # For each cell
            for row in range(m):
                for col in range(n):
                    if dp[row][col] > 0:
                        # Try all four directions
                        for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                            new_row = row + dx
                            new_col = col + dy
                            
                            if 0 <= new_row < m and 0 <= new_col < n:
                                temp[new_row][new_col] = (temp[new_row][new_col] + dp[row][col]) % MOD
                            else:
                                count = (count + dp[row][col]) % MOD
            
            dp = temp
        
        return count
    