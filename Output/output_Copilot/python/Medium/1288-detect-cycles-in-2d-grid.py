#https://leetcode.com/problems/detect-cycles-in-2d-grid/
#Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.
#A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.
#Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.
#Return true if any cycle of the same value exists in grid, otherwise, return false.
# 
#Example 1:
#Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
#Output: true
#Explanation: There are two valid cycles shown in different colors in the image below:
#Example 2:
#Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
#Output: true
#Explanation: There is only one valid cycle highlighted in the image below:
#Example 3:
#Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
#Output: false
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 500
#	grid consists only of lowercase English letters.
class Solution(object):
    def containsCycle(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: bool
        """
        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]

        def dfs(x, y, px, py):
            if visited[x][y]:
                return True
            visited[x][y] = True
            for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and (nx != px or ny != py) and grid[nx][ny] == grid[x][y]:
                    if dfs(nx, ny, x, y):
                        return True
            return False

        for i in range(m):
            for j in range(n):
                if not visited[i][j] and dfs(i, j, -1, -1):
                    return True
        return False        