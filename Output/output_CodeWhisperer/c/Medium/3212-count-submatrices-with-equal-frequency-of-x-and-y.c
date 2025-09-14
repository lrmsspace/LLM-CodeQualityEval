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
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int xCount = 0;
            int yCount = 0;
            int dotCount = 0;
            
            for (int k = i; k < rows; k++) {
                for (int l = j; l < cols; l++) {
                    if (grid[k][l] == 'X') {
                        xCount++;
                    } else if (grid[k][l] == 'Y') {
                        yCount++;
                    } else {
                        dotCount++;
                    }
                    
                    if (xCount == yCount && xCount > 0) {
                        count++;
                    }
                }
            }
        }
    }
    
    return count;    
}