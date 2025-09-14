#https://leetcode.com/problems/surface-area-of-3d-shapes/
#You are given an n x n grid where you have placed some 1 x 1 x 1 cubes. Each value v = grid[i][j] represents a tower of v cubes placed on top of cell (i, j).
#After placing these cubes, you have decided to glue any directly adjacent cubes to each other, forming several irregular 3D shapes.
#Return the total surface area of the resulting shapes.
#Note: The bottom face of each shape counts toward its surface area.
# 
#Example 1:
#Input: grid = [[1,2],[3,4]]
#Output: 34
#Example 2:
#Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
#Output: 32
#Example 3:
#Input: grid = [[2,2,2],[2,1,2],[2,2,2]]
#Output: 46
# 
#Constraints:
#	n == grid.length == grid[i].length
#	1 <= n <= 50
#	0 <= grid[i][j] <= 50
class Solution(object):
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        total_surface = 0
        for i in range(n):
            for j in range(n):
                # Add the area of the bottom face
                total_surface += grid[i][j] * 4
        
                # Add the areas of the four sides that are not on the boundary
                for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    ni, nj = i + dx, j + dy
                    if 0 <= ni < n and 0 <= nj < n:
                        total_surface += min(grid[i][j], grid[ni][nj]) * 2
        return total_surface
        