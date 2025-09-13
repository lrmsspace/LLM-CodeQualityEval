/*
 You are given a 2D matrix grid of size 3 x 3 consisting only of characters 'B' and 'W'. Character 'W' represents the white color, and character 'B' represents the black color.
 Your task is to change the color of at most one cell so that the matrix has a 2 x 2 square where all cells are of the same color.
 Return true if it is possible to create a 2 x 2 square of the same color, otherwise, return false.
 Example 1:
 Input: grid = [["B","W","B"],["B","W","W"],["B","W","B"]]
 Output: true
 Explanation:
 It can be done by changing the color of the grid[0][2].
 Example 2:
 Input: grid = [["B","W","B"],["W","B","W"],["B","W","B"]]
 Output: false
 Explanation:
 It cannot be done by changing at most one cell.
 Example 3:
 Input: grid = [["B","W","B"],["B","W","W"],["B","W","W"]]
 Output: true
 Explanation:
 The grid already contains a 2 x 2 square of the same color.
 Constraints:
 grid.length == 3
 grid[i].length == 3
 grid[i][j] is either 'W' or 'B'.
*/

bool canMakeSquare(char** grid, int gridSize, int* gridColSize) {
    int i, j, k, l, cnt = 0;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 'W') {
                cnt++;
            }
        }
    }
    if (cnt == 0 || cnt == gridSize * gridColSize[0]) {
        return true;
    }
    for (i = 0; i < gridSize - 1; i++) {
        for (j = 0; j < gridColSize[i] - 1; j++) {
            if (    grid[i][j] == grid[i][j + 1] &&
                    grid[i][j] == grid[i + 1][j] &&
                    grid[i][j] == grid[i + 1][j + 1]
)
            return true;
        }
    }
    return false;
    
}