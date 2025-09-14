# You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.
# Return the minimum possible sum of the area of these rectangles.
# Note that the rectangles are allowed to touch.
# Example 1:
# Input: grid = [[1,0,1],[1,1,1]]
# Output: 5
# Explanation:
# The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
# The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
# The 1 at (1, 1) is covered by a rectangle of area 1.
# Example 2:
# Input: grid = [[1,0,1,0],[0,1,0,1]]
# Output: 5
# Explanation:
# The 1's at (0, 0) and (0, 2) are covered by a rectangle of area 3.
# The 1 at (1, 1) is covered by a rectangle of area 1.
# The 1 at (1, 3) is covered by a rectangle of area 1.
# Constraints:
# 1 <= grid.length, grid[i].length <= 30
# grid[i][j] is either 0 or 1.
# The input is generated such that there are at least three 1's in grid.

class Solution(object):
    def minimumSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        rows = len(grid)
        cols = len(grid[0])
        total_area = 0

        # Find all 1's and their bounding boxes
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    # Find the bounding box for this 1
                    min_r, max_r = r, r
                    min_c, max_c = c, c
                    while max_r + 1 < rows and grid[max_r + 1][c] == 1:
                        max_r += 1
                    while max_c + 1 < cols and grid[r][max_c + 1] == 1:
                        max_c += 1
                    # Calculate the area of the rectangle
                    area = (max_r - min_r + 1) * (max_c - min_c + 1)
                    total_area += area

        return total_area