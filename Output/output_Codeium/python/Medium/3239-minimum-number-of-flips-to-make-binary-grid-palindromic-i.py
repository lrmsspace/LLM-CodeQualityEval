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
        m, n = len(grid), len(grid[0])
        rowFlip = [0] * m
        colFlip = [0] * n
        for i in range(m):
            for j in range(n//2):
                if grid[i][j] != grid[i][n-1-j]:
                    rowFlip[i] += 1
        for j in range(n):
            for i in range(m//2):
                if grid[i][j] != grid[m-1-i][j]:
                    colFlip[j] += 1
        rowFlip.sort()
        colFlip.sort()
        res = float('inf')
        for i in range(m+1):
            for j in range(n+1):
                res = min(res, i + j + rowFlip[i] + colFlip[j])
        return res
