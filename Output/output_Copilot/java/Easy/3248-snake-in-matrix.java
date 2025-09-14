/*
 There is a snake in an n x n matrix grid and can move in four possible directions. Each cell in the grid is identified by the position: grid[i][j] = (i * n) + j.
 The snake starts at cell 0 and follows a sequence of commands.
 You are given an integer n representing the size of the grid and an array of strings commands where each command[i] is either "UP", "RIGHT", "DOWN", and "LEFT". It's guaranteed that the snake will remain within the grid boundaries throughout its movement.
 Return the position of the final cell where the snake ends up after executing commands.
 Example 1:
 Input: n = 2, commands = ["RIGHT","DOWN"]
 Output: 3
 Explanation:
 0
 1
 2
 3
 0
 1
 2
 3
 0
 1
 2
 3
 Example 2:
 Input: n = 3, commands = ["DOWN","RIGHT","UP"]
 Output: 1
 Explanation:
 0
 1
 2
 3
 4
 5
 6
 7
 8
 0
 1
 2
 3
 4
 5
 6
 7
 8
 0
 1
 2
 3
 4
 5
 6
 7
 8
 0
 1
 2
 3
 4
 5
 6
 7
 8
 Constraints:
 2 <= n <= 10
 1 <= commands.length <= 100
 commands consists only of "UP", "RIGHT", "DOWN", and "LEFT".
 The input is generated such the snake will not move outside of the boundaries.
*/

class Solution {
    public int finalPositionOfSnake(int n, List<String> commands) {
        int x = 0, y = 0; // Starting position at (0, 0)

        for (String command : commands) {
            switch (command) {
                case "UP":
                    if (x > 0) x--; // Move up if not at the top edge
                    break;
                case "DOWN":
                    if (x < n - 1) x++; // Move down if not at the bottom edge
                    break;
                case "LEFT":
                    if (y > 0) y--; // Move left if not at the left edge
                    break;
                case "RIGHT":
                    if (y < n - 1) y++; // Move right if not at the right edge
                    break;
            }
        }

        return x * n + y; // Convert to linear position
        
    }
}