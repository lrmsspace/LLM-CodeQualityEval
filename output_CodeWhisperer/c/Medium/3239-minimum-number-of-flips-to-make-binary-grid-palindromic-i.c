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
    int m = gridSize, n = *gridColSize;
    int flips = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = grid[i][j];
            if (i > 0) sum += grid[i - 1][j];
            if (i < m - 1) sum += grid[i + 1][j];
            if (j > 0) sum += grid[i][j - 1];
            if (j < n - 1) sum += grid[i][j + 1];
            if (sum == 1 || sum == 3) flips++;
        }
    }
    return flips;    
}