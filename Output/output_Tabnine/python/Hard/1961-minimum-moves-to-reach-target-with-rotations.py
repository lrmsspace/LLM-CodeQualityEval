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
        # Define directions for the snake
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        # Initialize snake position and direction
        snake = [(0, 0), (0, 1)]
        direction = 0
        # Initialize moves count
        moves = 0
        # Initialize queue for BFS
        queue = deque([(0, 0)])
        # Initialize visited set
        visited = set([(0, 0)])
        # Initialize blocked cells set
        blocked = set()
        # Loop until the snake reaches the target
        while snake[-1] != (len(grid) - 1, len(grid[0]) - 2):
            # Get current position and next position
            current, next_pos = snake[-1], (snake[-1][0] + directions[direction][0], snake[-1][1] + directions[direction][1])
            # Check if next position is blocked
            if grid[next_pos[0]][next_pos[1]] == 1:
                return -1
            # Check if next position is outside grid
            if next_pos[0] < 0 or next_pos[0] >= len(grid) or next_pos[1] < 0 or next_pos[1] >= len(grid[0]):
                return -1
            # Check if next position has been visited
            if next_pos in visited:
                return -1
            # Check if next position is a blocked cell
            if next_pos in blocked:
                return -1
            # Add next position to visited set
            visited.add(next_pos)
            # Add next position to queue
            queue.append(next_pos)
            # Remove the head of the queue
            queue.popleft()
            # If the next position is the target, return the moves count
            if next_pos == (len(grid) - 1, len(grid[0]) - 2):
                return moves
            # If the snake has moved to the next position, update the snake position and direction
        # If the snake reaches the target without finding a way to reach the target, return -1
        return -1