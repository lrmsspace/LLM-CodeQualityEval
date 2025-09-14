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
        lands = []
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    lands.append((i, j))
        def bfs(x, y):
            queue = [(x, y, 0)]
            visited = set((x, y))
            while queue:
                cx, cy, d = queue.pop(0)
                for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    nx, ny = cx + dx, cy + dy
                    if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) and (nx, ny) not in visited:
                        if not grid[nx][ny]:
                            return d
                        queue.append((nx, ny, d + 1))
                        visited.add((nx, ny))
        ans = -1
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    ans = max(ans, bfs(i, j))
        return ans
