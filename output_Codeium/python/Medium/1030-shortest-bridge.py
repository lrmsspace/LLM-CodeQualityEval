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
        m, n = len(grid), len(grid[0])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        queue = collections.deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    queue.append((i, j, 0))
                    grid[i][j] = -1
                    break
            if queue:
                break

        while queue:
            x, y, step = queue.popleft()
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n:
                    if grid[nx][ny] == 1:
                        return step
                    elif grid[nx][ny] == 0:
                        queue.append((nx, ny, step + 1))
                        grid[nx][ny] = -1

        return -1
