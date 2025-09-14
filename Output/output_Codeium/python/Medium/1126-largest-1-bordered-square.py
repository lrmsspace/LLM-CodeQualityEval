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
        left, right, up = [[0]*n for _ in range(m)], [[0]*n for _ in range(m)], [[0]*n for _ in range(m)]
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    if j == 0: left[i][j] = 1
                    else: left[i][j] = left[i][j-1] + 1
                    if i == 0: up[i][j] = 1
                    else: up[i][j] = up[i-1][j] + 1
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if grid[i][j] == 1:
                    if j == n-1: right[i][j] = 1
                    else: right[i][j] = right[i][j+1] + 1
        for i in range(m):
            for j in range(n):
                ans = max(ans, min(left[i][j], right[i][j], up[i][j]))
        return ans * ans
