# You are given an m x n binary matrix grid.
# A row or column is considered palindromic if its values read the same forward and backward.
# You can flip any number of cells in grid from 0 to 1, or from 1 to 0.
# Return the minimum number of cells that need to be flipped to make either all rows palindromic or all columns palindromic.
# Example 1:
# Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
# Output: 2
# Explanation:
# Flipping the highlighted cells makes all the rows palindromic.
# Example 2:
# Input: grid = [[0,1],[0,1],[0,0]]
# Output: 1
# Explanation:
# Flipping the highlighted cell makes all the columns palindromic.
# Example 3:
# Input: grid = [[1],[0]]
# Output: 0
# Explanation:
# All rows are already palindromic.
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
        rows, cols = len(grid), len(grid[0])
        min_flips = 0
        
        # Count the number of 1s in each row and column
        row_ones = [sum(row) for row in grid]
        col_ones = [sum(col) for col in zip(*grid)]
        
        # Count the number of cells that need to be flipped to make a row or column palindromic
        for i in range(rows):
            min_flips += max(row_ones[i] - i, i - row_ones[i])
        
        for j in range(cols):
            min_flips += max(col_ones[j] - j, j - col_ones[j])
        
        return min_flips // 2
        