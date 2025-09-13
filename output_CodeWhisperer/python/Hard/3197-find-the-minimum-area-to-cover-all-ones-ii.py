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
        m, n = len(grid), len(grid[0])
        ans = float('inf')
        for i in range(m - 2):
            for j in range(n - 2):
                nums = [grid[i][j], grid[i][j + 1], grid[i][j + 2], grid[i + 1][j], grid[i + 1][j + 2], grid[i + 2][j], grid[i + 2][j + 1], grid[i + 2][j + 2]]
                nums.sort()
                ans = min(ans, nums[0] + nums[1] + nums[2] + nums[3] + nums[4] + nums[5] + nums[6] - nums[3])
        return ans
        