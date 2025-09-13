#https://leetcode.com/problems/shortest-path-in-binary-matrix/
#Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
#A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
#	All the visited cells of the path are 0.
#	All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
#The length of a clear path is the number of visited cells of this path.
# 
#Example 1:
#Input: grid = [[0,1],[1,0]]
#Output: 2
#Example 2:
#Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
#Output: 4
#Example 3:
#Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
#Output: -1
# 
#Constraints:
#	n == grid.length
#	n == grid[i].length
#	1 <= n <= 100
#	grid[i][j] is 0 or 1
class Solution(object):
    def shortestPathBinaryMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if grid[0][0] or grid[-1][-1]:
            return -1
        queue = [(0, 0, 1)]
        grid[0][0] = 1
        for x, y, step in queue:
            if x == y == len(grid) - 1:
                return step
            for dx, dy in ((-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)):
                nx, ny = x + dx, y + dy
                if 0 <= nx < len(grid) and 0 <= ny < len(grid) and not grid[nx][ny]:
                    queue.append((nx, ny, step + 1))
                    grid[nx][ny] = 1
        return -1
