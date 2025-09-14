#https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/
#In an n*n grid, there is a snake that spans 2 cells and starts moving from the top left corner at (0, 0) and (0, 1). The grid has empty cells represented by zeros and blocked cells represented by ones. The snake wants to reach the lower right corner at (n-1, n-2) and (n-1, n-1).
#In one move the snake can:
#	Move one cell to the right if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
#	Move down one cell if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
#	Rotate clockwise if it's in a horizontal position and the two cells under it are both empty. In that case the snake moves from (r, c) and (r, c+1) to (r, c) and (r+1, c).
#	
#	Rotate counterclockwise if it's in a vertical position and the two cells to its right are both empty. In that case the snake moves from (r, c) and (r+1, c) to (r, c) and (r, c+1).
#	
#Return the minimum number of moves to reach the target.
#If there is no way to reach the target, return -1.
# 
#Example 1:
#Input: grid = [[0,0,0,0,0,1],
#               [1,1,0,0,1,0],
#               [0,0,0,0,1,1],
#               [0,0,1,0,1,0],
#               [0,1,1,0,0,0],
#               [0,1,1,0,0,0]]
#Output: 11
#Explanation:
#One possible solution is [right, right, rotate clockwise, right, down, down, down, down, rotate counterclockwise, right, down].
#Example 2:
#Input: grid = [[0,0,1,1,1,1],
#               [0,0,0,0,1,1],
#               [1,1,0,0,0,1],
#               [1,1,1,0,0,1],
#               [1,1,1,0,0,1],
#               [1,1,1,0,0,0]]
#Output: 9
# 
#Constraints:
#	2 <= n <= 100
#	0 <= grid[i][j] <= 1
#	It is guaranteed that the snake starts at empty cells.
class Solution(object):
    def minimumMoves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        from collections import deque

        n = len(grid)
        directions = [(0, 1), (1, 0)]
        visited = set()
        queue = deque([(0, 0, 0)])
        visited.add((0, 0, 0))
        moves = 0

        while queue:
            for _ in range(len(queue)):
                x, y, orientation = queue.popleft()

                # Check if we reached the target
                if (x, y) == (n - 1, n - 2) and orientation == 0:
                    return moves

                # Move right or down
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 0:
                        if orientation == 0 and dx == 1:
                            if (nx, ny, 1) not in visited and nx + 1 < n and grid[nx + 1][ny] == 0:
                                visited.add((nx, ny, 1))
                                queue.append((nx, ny, 1))
                        elif orientation == 1 and dy == 1:
                            if (nx, ny, 0) not in visited and ny + 1 < n and grid[nx][ny + 1] == 0:
                                visited.add((nx, ny, 0))
                                queue.append((nx, ny, 0))
                        elif (nx, ny, orientation) not in visited:
                            visited.add((nx, ny, orientation))
                            queue.append((nx, ny, orientation))

                            # Rotate clockwise
                            if orientation == 0 and x + 1 < n and grid[x + 1][y] == 0 and grid[x + 1][y + 1] == 0:
                                if (x, y, 1) not in visited:
                                    visited.add((x, y, 1))
                                    queue.append((x, y, 1))

                            # Rotate counterclockwise
                            if orientation == 1 and y + 1 < n and grid[x][y + 1] == 0 and grid[x + 1][y + 1] == 0:
                                if (x, y, 0) not in visited:
                                    visited.add((x, y, 0))
                                    queue.append((x, y, 0))

                            moves += 1

                            return -1
        