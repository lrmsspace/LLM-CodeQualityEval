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
        n = len(grid)
        d = [0, 1, 0, -1, 0]
        def dfs(i, j, idx):
            grid[i][j] = idx
            area = 1
            for k in range(4):
                x, y = i + d[k], j + d[k + 1]
                if 0 <= x < n and 0 <= y < n and grid[x][y] == 1:
                    area += dfs(x, y, idx)
            return area
        idx = 2
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    dfs(i, j, idx)
                    idx += 1
        
        ans = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    area = 1
                    neighbors = set()
                    for k in range(4):
                        x, y = i + d[k], j + d[k + 1]
                        if 0 <= x < n and 0 <= y < n and grid[x][y] > 1:
                            neighbors.add(grid[x][y])
                    for neighbor in neighbors:
                        area += sizes[neighbor]
                    ans = max(ans, area)
        return ans if ans > 0 else n * n
