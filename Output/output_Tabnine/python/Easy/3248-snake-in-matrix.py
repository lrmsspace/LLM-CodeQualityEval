# There is a snake in an n x n matrix grid and can move in four possible directions. Each cell in the grid is identified by the position: grid[i][j] = (i * n) + j.
# The snake starts at cell 0 and follows a sequence of commands.
# You are given an integer n representing the size of the grid and an array of strings commands where each command[i] is either "UP", "RIGHT", "DOWN", and "LEFT". It's guaranteed that the snake will remain within the grid boundaries throughout its movement.
# Return the position of the final cell where the snake ends up after executing commands.
# Example 1:
# Input: n = 2, commands = ["RIGHT","DOWN"]
# Output: 3
# Explanation:
# 0
# 1
# 2
# 3
# 0
# 1
# 2
# 3
# 0
# 1
# 2
# 3
# Example 2:
# Input: n = 3, commands = ["DOWN","RIGHT","UP"]
# Output: 1
# Explanation:
# 0
# 1
# 2
# 3
# 4
# 5
# 6
# 7
# 8
# 0
# 1
# 2
# 3
# 4
# 5
# 6
# 7
# 8
# 0
# 1
# 2
# 3
# 4
# 5
# 6
# 7
# 8
# 0
# 1
# 2
# 3
# 4
# 5
# 6
# 7
# 8
# Constraints:
# 2 <= n <= 10
# 1 <= commands.length <= 100
# commands consists only of "UP", "RIGHT", "DOWN", and "LEFT".
# The input is generated such the snake will not move outside of the boundaries.

class Solution(object):
    def finalPositionOfSnake(self, n, commands):
        """
        :type n: int
        :type commands: List[str]
        :rtype: int
        """
        # Initialize the snake's position and direction
        snake = [(0, 0)]
        direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        
        # Initialize the current direction index
        direction_index = 0
        
        # Execute the commands
        for command in commands:
            dx, dy = direction[direction_index]
            new_x, new_y = snake[-1][0] + dx, snake[-1][1] + dy
            
            # Check if the new position is within the grid boundaries
            if 0 <= new_x < n and 0 <= new_y < n:
                snake.append((new_x, new_y))
            else:
                # Reverse the direction if the new position is outside the grid boundaries
                snake.pop()
                new_x, new_y = snake[-1][0] - dx, snake[-1][1] - dy
                snake.append((new_x, new_y))
                # Update the direction index
                if command == "RIGHT":
                    direction_index = (direction_index + 1) % 4
                elif command == "LEFT":
                    direction_index = (direction_index - 1) % 4
                    if direction_index < 0:
                        direction_index += 4
        
        # Return the final cell position
        return snake[-1][0] * n + snake[-1][1]
        