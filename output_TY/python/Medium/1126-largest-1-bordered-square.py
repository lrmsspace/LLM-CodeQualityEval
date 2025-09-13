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
        m, n = len(grid), len(grid[0])
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                if grid[i-1][j-1] == 1:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
        return max(max(row) for row in dp) ** 2