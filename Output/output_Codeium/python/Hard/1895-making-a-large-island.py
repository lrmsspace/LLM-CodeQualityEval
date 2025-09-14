#https://leetcode.com/problems/making-a-large-island/
#You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
#Return the size of the largest island in grid after applying this operation.
#An island is a 4-directionally connected group of 1s.
# 
#Example 1:
#Input: grid = [[1,0],[0,1]]
#Output: 3
#Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
#Example 2:
#Input: grid = [[1,1],[1,0]]
#Output: 4
#Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
#Example 3:
#Input: grid = [[1,1],[1,1]]
#Output: 4
#Explanation: Can't change any 0 to 1, only one island with area = 4.
# 
#Constraints:
#	n == grid.length
#	n == grid[i].length
#	1 <= n <= 500
#	grid[i][j] is either 0 or 1.
class Solution(object):
    def largestIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    grid[i][j] = 1
                    res = max(res, self.dfs(grid, i, j))
                    grid[i][j] = 0
        return res

    def dfs(self, grid, i, j):
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == 0:
            return 0
        grid[i][j] = 0
        return 1 + self.dfs(grid, i + 1, j) + self.dfs(grid, i - 1, j) + self.dfs(grid, i, j + 1) + self.dfs(grid, i, j - 1)
