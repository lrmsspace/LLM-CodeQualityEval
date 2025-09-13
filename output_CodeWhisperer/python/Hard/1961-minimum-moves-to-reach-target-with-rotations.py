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
        n = len(grid)
        queue = [(0, 0, 0, 1)]  # (row1, col1, row2, col2)
        visited = set([(0, 0, 0, 1)])
        steps = 0
        
        while queue:
            new_queue = []
            for row1, col1, row2, col2 in queue:
                if row1 == n - 1 and col1 == n - 2 and row2 == n - 1 and col2 == n - 1:
                    return steps
                # Move right
                if col2 + 1 < n and grid[row1][col2 + 1] == 0 and grid[row2][col2 + 1] == 0:
                    new_state = (row1, col1 + 1, row2, col2 + 1)
                    if new_state not in visited:
                        visited.add(new_state)
                        new_queue.append(new_state)
                # Move down
                if row2 + 1 < n and grid[row2 + 1][col2] == 0 and grid[row2 + 1][col1] == 0:
                    new_state = (row1 + 1, col1, row2 + 1, col2)
                    if new_state not in visited:
                        visited.add(new_state)
                        new_queue.append(new_state)
                # Rotate clockwise
                if row1 == row2 and col2 - col1 == 1 and row2 + 1 < n and grid[row2 + 1][col2] == 0 and grid[row2 + 1][col2 - 1] == 0:
                    new_state = (row1, col1, row1 + 1, col1)
                    if new_state not in visited:
                        visited.add(new_state)
                        new_queue.append(new_state)
                # Rotate counterclockwise
                if row1 == row2 and row2 + 1 < n and grid[row2 + 1][col2] == 0 and grid[row2 + 1][col1] == 0:
                    new_state = (row1, col1, row1, col1 + 1)
                    if new_state not in visited:
                        visited.add(new_state)
                        new_queue.append(new_state)
            queue = new_queue
            steps += 1
        
        return -1

        