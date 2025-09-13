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

int finalPositionOfSnake(int n, char** commands, int commandsSize) {
    int* grid = (int*)malloc(n * n * sizeof(int));
    int i, j, k, direction = 0; // 0 - right, 1 - down, 2 - left, 3 - up
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            grid[i * n + j] = (i * n) + j;
        }
    }
    
    i = 0;
    j = 0;
    while (k < commandsSize) {
        if (commands[k][0] == 'U') {
            direction = (direction + 3) % 4;
        } else if (commands[k][0] == 'D') {
            direction = (direction + 1) % 4;
        } else if (commands[k][0] == 'R') {
            direction = (direction + 2) % 4;
        } else {
            direction = (direction + 3) % 4;
        }
        
        if (direction == 0) {
            j = (j + 1) % n;
        } else if (direction == 1) {
            i = (i + 1) % n;
        } else if (direction == 2) {
            j = (j - 1 + n) % n;
        } else {
            i = (i - 1 + n) % n;
        }
        
        k++;
    
        grid[i * n + j] = -1; // mark the current cell as visited
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (grid[(i * n) + j] == -1) {
                    grid[(i * n) + j] = (i * n) + j; // reset the visited cell
                }
            }
        }
    }
    return grid[i * n + j]; // return the final cell position   
    
}