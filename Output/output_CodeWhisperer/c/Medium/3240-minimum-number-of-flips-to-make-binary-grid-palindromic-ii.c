/*
 You are given an m x n binary matrix grid.
 A row or column is considered palindromic if its values read the same forward and backward.
 You can flip any number of cells in grid from 0 to 1, or from 1 to 0.
 Return the minimum number of cells that need to be flipped to make all rows and columns palindromic, and the total number of 1's in grid divisible by 4.
 Example 1:
 Input: grid = [[1,0,0],[0,1,0],[0,0,1]]
 Output: 3
 Explanation:
 Example 2:
 Input: grid = [[0,1],[0,1],[0,0]]
 Output: 2
 Explanation:
 Example 3:
 Input: grid = [[1],[1]]
 Output: 2
 Explanation:
 Constraints:
 m == grid.length
 n == grid[i].length
 1 <= m * n <= 2 * 105
 0 <= grid[i][j] <= 1
*/

int minFlips(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int flips = 0;
    int ones = 0;
    
    // Count initial number of 1's
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) ones++;
        }
    }
    
    // Make rows palindromic
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n/2; j++) {
            if(grid[i][j] != grid[i][n-1-j]) {
                flips++;
                if(grid[i][j] == 1) ones--;
                else ones++;
            }
        }
    }
    
    // Make columns palindromic 
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < m/2; i++) {
            if(grid[i][j] != grid[m-1-i][j]) {
                flips++;
                if(grid[i][j] == 1) ones--;
                else ones++;
            }
        }
    }
    
    // Add flips needed to make total 1's divisible by 4
    int mod = ones % 4;
    if(mod != 0) {
        flips += (4 - mod);
    }
    
    return flips;
}       