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
    int i, j, k, l, m, n, count = 0, temp = 0;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                for (k = i - 1; k <= i + 1; k++) {
                    for (l = j - 1; l <= j + 1; l++) {
                        if (k >= 0 && k < gridSize && l >= 0 && l < gridColSize[i]) {
                            if (grid[k][l] == 0) {
                                temp++;
                            }
                        }
                    }
                }
                if (temp % 2 == 1) {
                    count++;
                }
            }
        }
    }
    return count;
    
}