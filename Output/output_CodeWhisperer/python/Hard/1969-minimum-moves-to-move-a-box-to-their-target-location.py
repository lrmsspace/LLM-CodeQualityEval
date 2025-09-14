#https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/
#A storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.
#The game is represented by an m x n grid of characters grid where each element is a wall, floor, or box.
#Your task is to move the box 'B' to the target position 'T' under the following rules:
#	The character 'S' represents the player. The player can move up, down, left, right in grid if it is a floor (empty cell).
#	The character '.' represents the floor which means a free cell to walk.
#	The character '#' represents the wall which means an obstacle (impossible to walk there).
#	There is only one box 'B' and one target cell 'T' in the grid.
#	The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a push.
#	The player cannot walk through the box.
#Return the minimum number of pushes to move the box to the target. If there is no way to reach the target, return -1.
# 
#Example 1:
#Input: grid = [["#","#","#","#","#","#"],
#               ["#","T","#","#","#","#"],
#               ["#",".",".","B",".","#"],
#               ["#",".","#","#",".","#"],
#               ["#",".",".",".","S","#"],
#               ["#","#","#","#","#","#"]]
#Output: 3
#Explanation: We return only the number of times the box is pushed.
#Example 2:
#Input: grid = [["#","#","#","#","#","#"],
#               ["#","T","#","#","#","#"],
#               ["#",".",".","B",".","#"],
#               ["#","#","#","#",".","#"],
#               ["#",".",".",".","S","#"],
#               ["#","#","#","#","#","#"]]
#Output: -1
#Example 3:
#Input: grid = [["#","#","#","#","#","#"],
#               ["#","T",".",".","#","#"],
#               ["#",".","#","B",".","#"],
#               ["#",".",".",".",".","#"],
#               ["#",".",".",".","S","#"],
#               ["#","#","#","#","#","#"]]
#Output: 5
#Explanation: push the box down, left, left, up and up.
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 20
#	grid contains only characters '.', '#', 'S', 'T', or 'B'.
#	There is only one character 'S', 'B', and 'T' in the grid.
class Solution(object):
    def minPushBox(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 'S':
                    player = (i, j)
                if grid[i][j] == 'B':
                    box = (i, j)
                if grid[i][j] == 'T':
                    target = (i, j)
        heap = [(0, box[0], box[1], player[0], player[1])]
        visited = set()
        while heap:
            step, bx, by, px, py = heapq.heappop(heap)
            if (bx, by) == target:
                return step
            if (bx, by, px, py) in visited:
                continue
            visited.add((bx, by, px, py))
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx, ny = bx - dx, by - dy
                if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] != '#':
                    if nx == px and ny == py:
                        heapq.heappush(heap, (step + 1, nx, ny, bx, by))
                    else:
                        heapq.heappush(heap, (step, bx, by, px, py))
        return -1

        