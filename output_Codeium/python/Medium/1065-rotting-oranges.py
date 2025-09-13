#https://leetcode.com/problems/rotting-oranges/
#You are given an m x n grid where each cell can have one of three values:
#	0 representing an empty cell,
#	1 representing a fresh orange, or
#	2 representing a rotten orange.
#Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
#Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
# 
#Example 1:
#Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
#Output: 4
#Example 2:
#Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
#Output: -1
#Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
#Example 3:
#Input: grid = [[0,2]]
#Output: 0
#Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 10
#	grid[i][j] is 0, 1, or 2.
class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        from collections import deque

        rows, cols = len(grid), len(grid[0])
        queue = deque()
        fresh_oranges = 0

        # Initialize the queue with all rotten oranges and count fresh oranges
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    queue.append((r, c))
                elif grid[r][c] == 1:
                    fresh_oranges += 1

        # If there are no fresh oranges, return 0 as no time is needed
        if fresh_oranges == 0:
            return 0

        minutes_passed = 0
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        # BFS to infect fresh oranges
        while queue:
            minutes_passed += 1
            for _ in range(len(queue)):
                x, y = queue.popleft()
                for dx, dy in directions:
                    new_x, new_y = x + dx, y + dy
                    if 0 <= new_x < rows and 0 <= new_y < cols and grid[new_x][new_y] == 1:
                        grid[new_x][new_y] = 2
                        fresh_oranges -= 1
                        queue.append((new_x, new_y))

        # If there are still fresh oranges, return -1
        return minutes_passed - 1 if fresh_oranges == 0 else -1

    