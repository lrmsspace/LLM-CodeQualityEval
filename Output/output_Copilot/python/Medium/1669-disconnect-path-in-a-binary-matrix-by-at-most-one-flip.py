#https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/
#You are given a 0-indexed m x n binary matrix grid. You can move from a cell (row, col) to any of the cells (row + 1, col) or (row, col + 1) that has the value 1. The matrix is disconnected if there is no path from (0, 0) to (m - 1, n - 1).
#You can flip the value of at most one (possibly none) cell. You cannot flip the cells (0, 0) and (m - 1, n - 1).
#Return true if it is possible to make the matrix disconnect or false otherwise.
#Note that flipping a cell changes its value from 0 to 1 or from 1 to 0.
# 
#Example 1:
#Input: grid = [[1,1,1],[1,0,0],[1,1,1]]
#Output: true
#Explanation: We can change the cell shown in the diagram above. There is no path from (0, 0) to (2, 2) in the resulting grid.
#Example 2:
#Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
#Output: false
#Explanation: It is not possible to change at most one cell such that there is not path from (0, 0) to (2, 2).
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 1000
#	1 <= m * n <= 105
#	grid[i][j] is either 0 or 1.
#	grid[0][0] == grid[m - 1][n - 1] == 1
class Solution(object):
    def isPossibleToCutPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]

        def dfs(x, y):
            if x == m - 1 and y == n - 1:
                return True
            visited[x][y] = True
            for dx, dy in [(1, 0), (0, 1)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny] and grid[nx][ny] == 1:
                    if dfs(nx, ny):
                        return True
            return False

        # Check if there's a path from (0, 0) to (m - 1, n - 1)
        if not dfs(0, 0):
            return True

        # Check if we can disconnect the path by flipping one cell
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    visited = [[False] * n for _ in range(m)]
                    if not dfs(0, 0):
                        return True
                    grid[i][j] = 1

        return False        