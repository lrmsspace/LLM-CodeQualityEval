#https://leetcode.com/problems/unique-paths-iii/
#You are given an m x n integer array grid where grid[i][j] could be:
#	1 representing the starting square. There is exactly one starting square.
#	2 representing the ending square. There is exactly one ending square.
#	0 representing empty squares we can walk over.
#	-1 representing obstacles that we cannot walk over.
#Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.
# 
#Example 1:
#Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
#Output: 2
#Explanation: We have the following two paths: 
#1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
#2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
#Example 2:
#Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
#Output: 4
#Explanation: We have the following four paths: 
#1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
#2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
#3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
#4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
#Example 3:
#Input: grid = [[0,1],[2,0]]
#Output: 0
#Explanation: There is no path that walks over every empty square exactly once.
#Note that the starting and ending square can be anywhere in the grid.
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 20
#	1 <= m * n <= 20
#	-1 <= grid[i][j] <= 2
#	There is exactly one starting cell and one ending cell.
class Solution(object):
    def uniquePathsIII(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        start_x, start_y = -1, -1
        empty_count = 0

        # Find the starting point and count empty cells
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    start_x, start_y = i, j
                elif grid[i][j] == 0:
                    empty_count += 1

        # Helper function for DFS
        def dfs(x, y, remaining):
            # If out of bounds or on an obstacle, return 0
            if x < 0 or x >= m or y < 0 or y >= n or grid[x][y] == -1:
                return 0
            # If we reach the end and have visited all empty cells, return 1
            if grid[x][y] == 2:
                return 1 if remaining == -1 else 0

            # Mark the cell as visited
            temp = grid[x][y]
            grid[x][y] = -1

            # Explore all 4 directions
            paths = (dfs(x + 1, y, remaining - 1) +
                 dfs(x - 1, y, remaining - 1) +
                 dfs(x, y + 1, remaining - 1) +
                 dfs(x, y - 1, remaining - 1))

            # Backtrack
            grid[x][y] = temp

            return paths

        # Start DFS from the starting point
        return dfs(start_x, start_y, empty_count)