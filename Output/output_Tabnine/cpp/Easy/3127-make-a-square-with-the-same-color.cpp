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
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Calculate the total number of 'W' and 'B' characters
        int whiteCount = 0;
        int blackCount = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 'W') {
                    whiteCount++;
                } else {
                    blackCount++;
                }
            }
        }
        
        // If the total number of 'W' and 'B' characters is not divisible by 4, it cannot form a 2 x 2 square
        if (whiteCount % 4!= 0 || blackCount % 4!= 0) {
            return false;
        }
        
        // Calculate the size of the square
        int squareSize = whiteCount / 4;
        int sideLength = sqrt(squareSize);
        if (sideLength * sideLength!= squareSize) {
            return false;
        }
        // Check if the grid can be divided into 2 x 2 squares of the same color
        for (int i = 0; i < rows - sideLength + 1; i++) {
            for (int j = 0; j < cols - sideLength + 1; j++) {
                if (checkSquare(grid, i, j, sideLength)) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
};