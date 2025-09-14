#https://leetcode.com/problems/largest-1-bordered-square/
#Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.
# 
#Example 1:
#Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
#Output: 9
#Example 2:
#Input: grid = [[1,1,0,0]]
#Output: 1
# 
#Constraints:
#	1 <= grid.length <= 100
#	1 <= grid[0].length <= 100
#	grid[i][j] is 0 or 1
class Solution(object):
    def largest1BorderedSquare(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        dp = [[0] * n for _ in range(m)]
        max_len = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                    max_len = max(max_len, dp[i][j])
        return max_len * max_len if max_len > 0 else 0        