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
        int n = grid.length;
        int sum = 0;
        int[] colorCount = new int[2];
        
        // Count the number of 'W' and 'B' characters and calculate the sum
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'W') {
                    colorCount[0]++;
                    sum++;
                } else {
                    colorCount[1]++;
                }
            }
        }
        
        // Check if the sum of 'W' and 'B' characters is odd
        if (sum % 2!= 0) {
            return false;
        }
        
        // Find the smallest possible side length of the square
        int sideLength = sum / 4;
        
        // Check if it is possible to create a 2 x 2 square of the same color
        for (int i = 0; i <= sideLength; i++) {
            for (int j = 0; j <= sideLength; j++) {
                if (checkSquare(grid, i, j, colorCount)) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
}