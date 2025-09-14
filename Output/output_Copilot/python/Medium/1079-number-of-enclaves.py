#https://leetcode.com/problems/number-of-enclaves/
#You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
#A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
#Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
# 
#Example 1:
#Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
#Output: 3
#Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
#Example 2:
#Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
#Output: 0
#Explanation: All 1s are either on the boundary or can reach the boundary.
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 500
#	grid[i][j] is either 0 or 1.
class Solution(object):
    def numEnclaves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]

        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n:
                return False
            if grid[i][j] == 0 or visited[i][j]:
                return True
            visited[i][j] = True
            up = dfs(i - 1, j)
            down = dfs(i + 1, j)
            left = dfs(i, j - 1)
            right = dfs(i, j + 1)
            return up and down and left and right

        for i in range(m):
            for j in range(n):
                if (i == 0 or i == m - 1 or j == 0 or j == n - 1) and grid[i][j] == 1:
                    dfs(i, j)

        count = sum(grid[i][j] == 1 and not visited[i][j] for i in range(m) for j in range(n))
        return count        