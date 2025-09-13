/*
 You are given an m x n binary matrix grid.
 A row or column is considered palindromic if its values read the same forward and backward.
 You can flip any number of cells in grid from 0 to 1, or from 1 to 0.
 Return the minimum number of cells that need to be flipped to make either all rows palindromic or all columns palindromic.
 Example 1:
 Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
 Output: 2
 Explanation:
 Flipping the highlighted cells makes all the rows palindromic.
 Example 2:
 Input: grid = [[0,1],[0,1],[0,0]]
 Output: 1
 Explanation:
 Flipping the highlighted cell makes all the columns palindromic.
 Example 3:
 Input: grid = [[1],[0]]
 Output: 0
 Explanation:
 All rows are already palindromic.
 Constraints:
 m == grid.length
 n == grid[i].length
 1 <= m * n <= 2 * 105
 0 <= grid[i][j] <= 1
*/

int minFlips(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = *gridColSize;
    int flips = 0;
    int rowCount = 0;
    int colCount = 0;
    
    // Count the number of 1s in each row and column
    for (int i = 0; i < m; i++) {
        rowCount = 0;
        colCount = 0;
        for (int j = 0; j < n; j++) {
            rowCount += grid[i][j];
            colCount += grid[j][i];
        }
        
        // Count the number of flips needed to make the row and column palindromic
        flips += min(rowCount, m - rowCount);
        flips += min(colCount, n - colCount);
    }
    
    return flips;
    
}