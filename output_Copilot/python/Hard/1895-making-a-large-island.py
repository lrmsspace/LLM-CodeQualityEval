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
        def dfs(i, j, index):
            if i < 0 or i >= n or j < 0 or j >= n or grid[i][j] != 1:
                return 0
            grid[i][j] = index
            area = 1
            for x, y in directions:
                area += dfs(i + x, j + y, index)
            return area

        n = len(grid)
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        index = 2
        areas = {0: 0}  
        max_area = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    area = dfs(i, j, index)
                    areas[index] = area
                    max_area = max(max_area, area)
                    index += 1
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    seen = set()
                    area = 1  
                    for x, y in directions:
                        ni, nj = i + x, j + y
                        if 0 <= ni < n and 0 <= nj < n and grid[ni][nj] > 1:
                            idx = grid[ni][nj]
                            if idx not in seen:
                                area += areas[idx]
                                seen.add(idx)
                    max_area = max(max_area, area)
        return max_area      