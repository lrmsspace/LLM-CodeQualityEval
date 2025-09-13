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
    int n = *gridColSize;
    int flipCount = 0;
    int oneCount = 0;
    
    // Count the number of 1's and calculate the total number of flips needed
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                oneCount++;
            }
            flipCount += abs(grid[i][j] - 1); // Flip the cell to make it palindromic
        }
    }
    
    // Calculate the number of flips needed to make all rows and columns palindromic
    flipCount = (flipCount + 1) / 2;
    
    // Return the minimum number of flips and the total number of 1's divisible by 4
    return flipCount * 2 + oneCount % 4;
    
}