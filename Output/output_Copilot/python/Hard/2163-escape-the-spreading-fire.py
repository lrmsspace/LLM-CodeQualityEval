#https://leetcode.com/problems/escape-the-spreading-fire/
#You are given a 0-indexed 2D integer array grid of size m x n which represents a field. Each cell has one of three values:
#	0 represents grass,
#	1 represents fire,
#	2 represents a wall that you and fire cannot pass through.
#You are situated in the top-left cell, (0, 0), and you want to travel to the safehouse at the bottom-right cell, (m - 1, n - 1). Every minute, you may move to an adjacent grass cell. After your move, every fire cell will spread to all adjacent cells that are not walls.
#Return the maximum number of minutes that you can stay in your initial position before moving while still safely reaching the safehouse. If this is impossible, return -1. If you can always reach the safehouse regardless of the minutes stayed, return 109.
#Note that even if the fire spreads to the safehouse immediately after you have reached it, it will be counted as safely reaching the safehouse.
#A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
# 
#Example 1:
#Input: grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
#Output: 3
#Explanation: The figure above shows the scenario where you stay in the initial position for 3 minutes.
#You will still be able to safely reach the safehouse.
#Staying for more than 3 minutes will not allow you to safely reach the safehouse.
#Example 2:
#Input: grid = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
#Output: -1
#Explanation: The figure above shows the scenario where you immediately move towards the safehouse.
#Fire will spread to any cell you move towards and it is impossible to safely reach the safehouse.
#Thus, -1 is returned.
#Example 3:
#Input: grid = [[0,0,0],[2,2,0],[1,2,0]]
#Output: 1000000000
#Explanation: The figure above shows the initial grid.
#Notice that the fire is contained by walls and you will always be able to safely reach the safehouse.
#Thus, 109 is returned.
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	2 <= m, n <= 300
#	4 <= m * n <= 2 * 104
#	grid[i][j] is either 0, 1, or 2.
#	grid[0][0] == grid[m - 1][n - 1] == 0
class Solution(object):
    def maximumMinutes(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        from collections import deque

        m, n = len(grid), len(grid[0])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        def bfs_fire():
            fire_time = [[float('inf')] * n for _ in range(m)]
            queue = deque()

            for i in range(m):
                for j in range(n):
                    if grid[i][j] == 2:
                        queue.append((i, j))
                        fire_time[i][j] = 0

            while queue:
                x, y = queue.popleft()
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 0 and fire_time[nx][ny] == float('inf'):
                        fire_time[nx][ny] = fire_time[x][y] + 1
                        queue.append((nx, ny))

            return fire_time

        def bfs_player(wait_time):
            player_time = [[float('inf')] * n for _ in range(m)]
            queue = deque([(0, 0)])
            player_time[0][0] = wait_time

            while queue:
                x, y = queue.popleft()
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 0:
                        if player_time[nx][ny] > player_time[x][y] + 1:
                            player_time[nx][ny] = player_time[x][y] + 1
                            queue.append((nx, ny))

            return player_time

        fire_time = bfs_fire()
        left, right = -1, int(1e9)

        while left < right:
            mid = (left + right + 1) // 2
            player_time = bfs_player(mid)
            if player_time[m - 1][n - 1] <= fire_time[m - 1][n - 1]:
                right = mid - 1
            else:
                left = mid

        if left == int(1e9):
            return int(1e9)
        elif left == -1:   
            return 0
        else:
            return left + 1 if fire_time[m - 1][n - 1] > left else left
# Test case     