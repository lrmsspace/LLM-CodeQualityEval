#https://leetcode.com/problems/coloring-a-border/
#You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location.
#Two squares are called adjacent if they are next to each other in any of the 4 directions.
#Two squares belong to the same connected component if they have the same color and they are adjacent.
#The border of a connected component is all the squares in the connected component that are either adjacent to (at least) a square not in the component, or on the boundary of the grid (the first or last row or column).
#You should color the border of the connected component that contains the square grid[row][col] with color.
#Return the final grid.
# 
#Example 1:
#Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
#Output: [[3,3],[3,2]]
#Example 2:
#Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
#Output: [[1,3,3],[2,3,3]]
#Example 3:
#Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
#Output: [[2,2,2],[2,1,2],[2,2,2]]
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 50
#	1 <= grid[i][j], color <= 1000
#	0 <= row < m
#	0 <= col < n
class Solution(object):
    def colorBorder(self, grid, row, col, color):
        """
        :type grid: List[List[int]]
        :type row: int
        :type col: int
        :type color: int
        :rtype: List[List[int]]
        """
        m, n = len(grid), len(grid[0])
        ans = [row[:] for row in grid]
        q = [(row, col)]
        while q:
            i, j = q.pop()
            if grid[i][j] == 0: continue
            grid[i][j] = 0
            if i == 0 or grid[i-1][j] != grid[i][j] or (i+1==m and grid[i+1][j] != grid[i][j]):
                ans[i][j] = color
            if j == 0 or grid[i][j-1] != grid[i][j] or (j+1==n and grid[i][j+1] != grid[i][j]):
                ans[i][j] = color
            for x, y in [(i-1, j), (i+1, j), (i, j-1)]:
                i, j-1), (i, j+1)
        for i, j in q: grid[i][j] = color
        return ans