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

class Solution {
    public boolean canMakeSquare(char[][] grid) {
        // Check all possible 2x2 squares in the 3x3 grid
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                // Count the number of 'B' and 'W' in the current 2x2 square
                int countB = 0, countW = 0;
                for (int x = i; x < i + 2; x++) {
                    for (int y = j; y < j + 2; y++) {
                        if (grid[x][y] == 'B') {
                            countB++;
                        } else {
                            countW++;
                        }
                    }
                }
                // If we can change one cell to make all cells the same color
                if (countB >= 3 || countW >= 3) {
                    return true;
                }
            }
        }
        return false; // No valid square found
        
    }
}