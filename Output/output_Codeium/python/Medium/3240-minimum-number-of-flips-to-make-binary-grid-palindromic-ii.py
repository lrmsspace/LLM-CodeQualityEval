# You are given an m x n binary matrix grid.
# A row or column is considered palindromic if its values read the same forward and backward.
# You can flip any number of cells in grid from 0 to 1, or from 1 to 0.
# Return the minimum number of cells that need to be flipped to make all rows and columns palindromic, and the total number of 1's in grid divisible by 4.
# Example 1:
# Input: grid = [[1,0,0],[0,1,0],[0,0,1]]
# Output: 3
# Explanation:
# Example 2:
# Input: grid = [[0,1],[0,1],[0,0]]
# Output: 2
# Explanation:
# Example 3:
# Input: grid = [[1],[1]]
# Output: 2
# Explanation:
# Constraints:
# m == grid.length
# n == grid[i].length
# 1 <= m * n <= 2 * 105
# 0 <= grid[i][j] <= 1

class Solution(object):
    def minFlips(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        min_flips = float('inf')
        
        # Function to calculate flips required to make a row palindromic
        def row_flips(row):
            return sum(1 for i in range(n // 2) if row[i] != row[n - 1 - i])
        
        # Function to calculate flips required to make a column palindromic
        def col_flips(col):
            return sum(1 for i in range(m // 2) if grid[i][col] != grid[m - 1 - i][col])
        
        # Calculate minimum flips for rows
        for i in range(m):
            flips = row_flips(grid[i])
            min_flips = min(min_flips, flips)
        
        # Calculate minimum flips for columns
        for j in range(n):
            flips = col_flips(j)
            min_flips = min(min_flips, flips)
        
        # Calculate total number of 1's in the grid
        total_ones = sum(sum(row) for row in grid)
        
        # Check if total number of 1's is divisible by 4
        if total_ones % 4 != 0:
            return -1
        
        return min_flips

