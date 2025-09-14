# You are given a 2D matrix grid consisting of positive integers.
# You have to select one or more cells from the matrix such that the following conditions are satisfied:
# No two selected cells are in the same row of the matrix.
# The values in the set of selected cells are unique.
# Your score will be the sum of the values of the selected cells.
# Return the maximum score you can achieve.
# Example 1:
# Input: grid = [[1,2,3],[4,3,2],[1,1,1]]
# Output: 8
# Explanation:
# We can select the cells with values 1, 3, and 4 that are colored above.
# Example 2:
# Input: grid = [[8,7,6],[8,3,2]]
# Output: 15
# Explanation:
# We can select the cells with values 7 and 8 that are colored above.
# Constraints:
# 1 <= grid.length, grid[i].length <= 10
# 1 <= grid[i][j] <= 100

class Solution(object):
    def maxScore(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows, cols = len(grid), len(grid[0])
        dp = [[0] * cols for _ in range(rows)]
        dp[0][0] = grid[0][0]
        
        for i in range(1, rows):
            dp[i][0] = dp[i-1][0] + grid[i][0]
        
        for j in range(1, cols):
            dp[0][j] = dp[0][j-1] + grid[0][j]
        
        for i in range(1, rows):
            for j in range(1, cols):
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j]
        
        return dp[rows-1][cols-1]   
        