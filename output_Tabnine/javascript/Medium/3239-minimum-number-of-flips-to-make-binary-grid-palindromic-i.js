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

/**
 * @param {number[][]} grid
 * @return {number}
 */
var minFlips = function(grid) {
    let m = grid.length;
    let n = grid[0].length;
    let rowFlips = 0;
    let colFlips = 0;
    
    // Count the number of 1s in each row and column
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                rowFlips += (i % 2 === 0)? 1 : 0;
                colFlips += (j % 2 === 0)? 1 : 0;
            }
        }
    }
    
    // Calculate the minimum number of flips required to make each row palindromic
    for (let i = 0; i < m; i++) {
        rowFlips = Math.min(rowFlips, m - rowFlips);
    }
    // Calculate the minimum number of flips required to make each column palindromic
    for (let j = 0; j < n; j++) {
        colFlips = Math.min(colFlips, n - colFlips);
    }
    
    // Return the minimum number of flips required to make either all rows or all columns palindromic
    return Math.min(rowFlips, colFlips);
    
};