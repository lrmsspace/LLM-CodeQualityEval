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

class Solution {
    public int numberOfSubmatrices(char[][] grid) {
        int count = 0;
        int rows = grid.length;
        int cols = grid[0].length;

        for (int r1 = 0; r1 < rows; r1++) {
            for (int r2 = r1; r2 < rows; r2++) {
                int xCount = 0;
                int yCount = 0;

                for (int c = 0; c < cols; c++) {
                    for (int r = r1; r <= r2; r++) {
                        if (grid[r][c] == 'X') {
                            xCount++;
                        } else if (grid[r][c] == 'Y') {
                            yCount++;
                        }
                    }

                    if (xCount == yCount && xCount > 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
}