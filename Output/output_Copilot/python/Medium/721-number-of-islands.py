#https://leetcode.com/problems/number-of-islands/
#Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
#An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
# 
#Example 1:
#Input: grid = [
#  ["1","1","1","1","0"],
#  ["1","1","0","1","0"],
#  ["1","1","0","0","0"],
#  ["0","0","0","0","0"]
#]
#Output: 1
#Example 2:
#Input: grid = [
#  ["1","1","0","0","0"],
#  ["1","1","0","0","0"],
#  ["0","0","1","0","0"],
#  ["0","0","0","1","1"]
#]
#Output: 3
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 300
#	grid[i][j] is '0' or '1'.
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0
        
        rows, cols = len(grid), len(grid[0])
        visited = [[False] * cols for _ in range(rows)]
        
        def dfs(r, c):
            if r < 0 or r >= rows or c < 0 or c >= cols or grid[r][c] == '0' or visited[r][c]:
                return
            visited[r][c] = True
            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)   
        
        island_count = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == '1' and not visited[r][c]:
                    dfs(r, c)
                    island_count += 1
        return island_count