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
        if grid[0][0] == 1 or grid[-1][-1] == 1:
            return -1
        n = len(grid)
        queue = collections.deque([(0, 0, 1)])
        grid[0][0] = 1
        while queue:
            i, j, d = queue.popleft()
            if i == n-1 and j == n-1:
                return d
            for x, y in ((i-1, j-1), (i-1, j), (i-1, j+1), (i, j-1), (i, j+1), (i+1, j-1), (i+1, j), (i+1, j+1)):
                if 0 <= x < n and 0 <= y < n and grid[x][y] == 0:
                    grid[x][y] = 1
                    queue.append((x, y, d+1))
        return -1

        