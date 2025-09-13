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
        dp = [[[0] * cols for _ in range(rows)] for _ in range(rows)]
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    dp[i][j][0] = 1
                    if i > 0:
                        dp[i][j][0] += dp[i-1][j][0]
                    if j > 0:
                        dp[i][j][0] += dp[i][j-1][0]
        
        max_area = 0
        for i in range(rows):
            for j in range(cols):
                for k in range(i, rows):
                    for l in range(j, cols):
                        area = dp[k][l][0]
                        if i > 0:
                            area -= dp[i-1][l][0]
                        if j > 0:
                            area -= dp[k][j-1][0]
                        if i > 0 and j > 0:
                            area += dp[i-1][j-1][0]
                        max_area = max(max_area, area)  
        return max_area * 3 
        