#https://leetcode.com/problems/shortest-bridge/
#You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
#An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
#You may change 0's to 1's to connect the two islands to form one island.
#Return the smallest number of 0's you must flip to connect the two islands.
# 
#Example 1:
#Input: grid = [[0,1],[1,0]]
#Output: 1
#Example 2:
#Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
#Output: 2
#Example 3:
#Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
#Output: 1
# 
#Constraints:
#	n == grid.length == grid[i].length
#	2 <= n <= 100
#	grid[i][j] is either 0 or 1.
#	There are exactly two islands in grid.
class Solution(object):
    def shortestBridge(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def dfs(i, j):
            if 0 <= i < len(grid) and 0 <= j < len(grid[0]) and grid[i][j] == 1:
                grid[i][j] = 2  # mark as visited
                directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
                for dx, dy in directions:
                    dfs(i + dx, j + dy)
        
        # Find the first island
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    dfs(i, j)
                    break
        
        # Breadth-first search to find the shortest distance between the two islands
        queue = [(i, j) for i in range(len(grid)) for j in range(len(grid[0])) if grid[i][j] == 2]
        visited = set(queue)
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        min_steps = float('inf')
        
        while queue:
            size = len(queue)
            for _ in range(size):
                x, y = queue.pop(0)
                if grid[x][y] == 3:
                    min_steps = min(min_steps, abs(x - len(grid) // 2) + abs(y - len(grid[0]) // 2))
        
        return min_steps - 1  # subtract 1 to account for the initial flips 
        