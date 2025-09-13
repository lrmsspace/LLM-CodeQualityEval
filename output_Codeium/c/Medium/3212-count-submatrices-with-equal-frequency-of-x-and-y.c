/*
 Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
 grid[0][0]
 an equal frequency of 'X' and 'Y'.
 at least one 'X'.
 Example 1:
 Input: grid = [["X","Y","."],["Y",".","."]]
 Output: 3
 Explanation:
 Example 2:
 Input: grid = [["X","X"],["X","Y"]]
 Output: 0
 Explanation:
 No submatrix has an equal frequency of 'X' and 'Y'.
 Example 3:
 Input: grid = [[".","."],[".","."]]
 Output: 0
 Explanation:
 No submatrix has at least one 'X'.
 Constraints:
 1 <= grid.length, grid[i].length <= 1000
 grid[i][j] is either 'X', 'Y', or '.'.
*/

int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
    int count = 0;
    int rows = gridSize;
    int cols = gridColSize[0];
    int* rowX = (int*)malloc(rows * sizeof(int));
    int* rowY = (int*)malloc(rows * sizeof(int));
    
    for (int i = 0; i < rows; i++) {
        rowX[i] = 0;
        rowY[i] = 0;
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'X') {
                rowX[i]++;
            } else if (grid[i][j] == 'Y') {
                rowY[i]++;
            }
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = i; j < rows; j++) {
            int xCount = 0;
            int yCount = 0;
            for (int k = i; k <= j; k++) {
                xCount += rowX[k];
                yCount += rowY[k];
            }
            if (xCount == yCount) {
                count++;
            }
        }
    }
    
    free(rowX);
    free(rowY);
    
    return count;
}