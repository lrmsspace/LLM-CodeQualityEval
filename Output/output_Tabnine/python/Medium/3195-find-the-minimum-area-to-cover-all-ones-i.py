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
        if not grid or not grid[0]:
            return 0
        
        rows, cols = len(grid), len(grid[0])
        dp = [[0] * cols for _ in range(rows)]
        
        min_area = float('inf')
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    dp[i][j] = 1
                    if i > 0:
                        dp[i][j] += dp[i-1][j]
                    if j > 0:
                        dp[i][j] += dp[i][j-1]
                    if i > 0 and j > 0:
                        dp[i][j] -= dp[i-1][j-1]
                    min_area = min(min_area, dp[i][j])
        
        return min_area * min_area
        