#https://leetcode.com/problems/number-of-closed-islands/
#Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
#Return the number of closed islands.
# 
#Example 1:
#Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
#Output: 2
#Explanation: 
#Islands in gray are closed because they are completely surrounded by water (group of 1s).
#Example 2:
#Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
#Output: 1
#Example 3:
#Input: grid = [[1,1,1,1,1,1,1],
#               [1,0,0,0,0,0,1],
#               [1,0,1,1,1,0,1],
#               [1,0,1,0,1,0,1],
#               [1,0,1,1,1,0,1],
#               [1,0,0,0,0,0,1],
#               [1,1,1,1,1,1,1]]
#Output: 2
# 
#Constraints:
#	1 <= grid.length, grid[0].length <= 100
#	0 <= grid[i][j] <=1
class Solution(object):
    def closedIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]

        def dfs(x, y):
            if x < 0 or x >= m or y < 0 or y >= n:
                return False
            if grid[x][y] == 1:
                return True
            if visited[x][y]:
                return True
            visited[x][y] = True
            up = dfs(x - 1, y)
            down = dfs(x + 1, y)
            left = dfs(x, y - 1)
            right = dfs(x, y + 1)
            return up and down and left and right

        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and not visited[i][j]:
                    if dfs(i, j):
                        count += 1

        return count        