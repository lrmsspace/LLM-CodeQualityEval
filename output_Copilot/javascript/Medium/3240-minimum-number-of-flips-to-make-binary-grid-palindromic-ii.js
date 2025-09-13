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

/**
 * @param {number[][]} grid
 * @return {number}
 */
var minFlips = function(grid) {
    const m = grid.length, n = grid[0].length;
    let rowFlips = 0, colFlips = 0;

    // Count flips needed for rows
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < Math.floor(n / 2); j++) {
            if (grid[i][j] !== grid[i][n - 1 - j]) {
                rowFlips++;
            }
        }
    }

    // Count flips needed for columns
    for (let j = 0; j < n; j++) {
        for (let i = 0; i < Math.floor(m / 2); i++) {
            if (grid[i][j] !== grid[m - 1 - i][j]) {
                colFlips++;
            }
        }
    }

    return Math.min(rowFlips, colFlips);
};