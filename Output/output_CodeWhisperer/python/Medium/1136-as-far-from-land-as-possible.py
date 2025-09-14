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
        n = len(grid)
        queue = collections.deque()
        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    queue.append((i, j))
        if len(queue) == 0 or len(queue) == n * n:
            return -1
        distance = -1
        while queue:
            for _ in range(len(queue)):
                i, j = queue.popleft()
                for x, y in ((i-1, j), (i+1, j), (i, j-1), (i, j+1)):
                    if 0 <= x < n and 0 <= y < n and grid[x][y] == 0:
                        grid[x][y] = 1
                        queue.append((x, y))
            distance += 1
        return distance

        