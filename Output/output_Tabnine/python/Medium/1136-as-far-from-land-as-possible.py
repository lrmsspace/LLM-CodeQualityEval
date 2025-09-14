#https://leetcode.com/problems/as-far-from-land-as-possible/
#Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.
#The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
# 
#Example 1:
#Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
#Output: 2
#Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
#Example 2:
#Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
#Output: 4
#Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
# 
#Constraints:
#	n == grid.length
#	n == grid[i].length
#	1 <= n <= 100
#	grid[i][j] is 0 or 1
class Solution(object):
    def maxDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # Step 1: Initialize variables
        n = len(grid)
        max_distance = -1
        queue = []
        
        # Step 2: Iterate through the grid to find water cells
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    queue.append((i, j, 0))
        
        # Step 3: Breadth-first search to find the maximum distance from a water cell to a land cell
        while queue:
            x, y, distance = queue.pop(0)
            max_distance = max(max_distance, distance)
            
            # Step 3.1: Check the adjacent cells
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 1:
                    queue.append((nx, ny, distance + 1))
                    grid[nx][ny] = 0
        
        # Step 4: Return the maximum distance or -1 if no land or water exists
        return max_distance
        