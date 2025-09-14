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

        # Count the number of flips required to make all rows palindromic
        rowFlips = 0
        for i in range(len(grid)):
            row = grid[i]
            # Count the number of flips required for the current row
            rowFlips += self.countFlips(row)

        # Count the number of flips required to make all columns palindromic
        colFlips = 0
        for j in range(len(grid[0])):
            col = [grid[i][j] for i in range(len(grid))]
            # Count the number of flips required for the current column
            colFlips += self.countFlips(col)

        # Return the minimum number of flips required
        return min(rowFlips, colFlips)

    def countFlips(self, arr):
        """
        Count the number of flips required to make the array palindromic
        """
        flips = 0
        n = len(arr)
        for i in range(n // 2):
            if arr[i] != arr[n - i - 1]:
                flips += 1
        return flips