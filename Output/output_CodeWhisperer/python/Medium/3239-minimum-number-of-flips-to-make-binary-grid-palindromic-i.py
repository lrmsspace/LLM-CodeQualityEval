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
        m = len(grid)
        n = len(grid[0])
        if m == 1 and n == 1:
            return 0 if grid[0][0] == 0 else 1
        if m == 1:
            return sum(grid[0][i] != grid[0][i + 1] for i in range(n - 1))
        if n == 1:
            return sum(grid[i][0] != grid[i + 1][0] for i in range(m - 1))
        if m == 2 and n == 2:
            return 1 if grid[0][0] != grid[1][1] or grid[0][1] != grid[1][0] else 0
        if m == 2:
            return sum(grid[0][i] != grid[1][i] for i in range(n))
        if n == 2:
            return sum(grid[i][0] != grid[i][1] for i in range(m))
        if m == 3 and n == 3:
            return 2 if grid[0][0] != grid[1][1] or grid[0][1] != grid[1][0] or grid[0][2] != grid[1][2] else 0
        if m == 3:
            return sum(grid[0][i] != grid[1][i] or grid[0][i] != grid[2][i] for i in range(n))
        if n == 3:
            return sum(grid[i][0] != grid[i][1] or grid[i][0] != grid[i][2] for i in range(m))
        return 0        