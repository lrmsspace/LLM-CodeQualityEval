# You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.
# Return the minimum possible area of the rectangle.
# Example 1:
# Input: grid = [[0,1,0],[1,0,1]]
# Output: 6
# Explanation:
# The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.
# Example 2:
# Input: grid = [[1,0],[0,0]]
# Output: 1
# Explanation:
# The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.
# Constraints:
# 1 <= grid.length, grid[i].length <= 1000
# grid[i][j] is either 0 or 1.
# The input is generated such that there is at least one 1 in grid.

class Solution(object):
    def minimumArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        min_row = float('inf')
        max_row = float('-inf')
        min_col = float('inf')
        max_col = float('-inf')

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    min_row = min(min_row, i)
                    max_row = max(max_row, i)
                    min_col = min(min_col, j)
                    max_col = max(max_col, j)

        if min_row == float('inf'):
            return 0

        return (max_row - min_row + 1) * (max_col - min_col + 1)
