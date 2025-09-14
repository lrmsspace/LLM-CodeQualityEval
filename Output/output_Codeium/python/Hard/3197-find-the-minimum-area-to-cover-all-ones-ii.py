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
        rows, cols = len(grid), len(grid[0])
        min_sum = float('inf')
        
        def dfs(r1, c1, r2, c2, s):
            nonlocal min_sum
            if s == 3:
                min_sum = min(min_sum, (r2 - r1 + 1) * (c2 - c1 + 1))
                return
            for r in range(rows):
                for c in range(cols):
                    if grid[r][c] == 1 and r1 <= r <= r2 and c1 <= c <= c2:
                        grid[r][c] = 0
                        dfs(r1, c1, r2, c, s + 1)
                        dfs(r1, c, r2, c2, s + 1)
                        dfs(r, c1, r2, c2, s + 1)
                        dfs(r1, c1, r, c2, s + 1)
                        grid[r][c] = 1
                        
        dfs(0, 0, rows - 1, cols - 1, 0)
        return min_sum

