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
    const m = grid.length;
    const n = grid[0].length;
    const total = m * n;
    const totalOnes = grid.reduce((acc, row) => acc + row.reduce((acc, cell) => acc + cell, 0), 0);
    const isPalindrome = (row, col) => {
        const isRowPalindrome = (row) => {
            let left = 0;
            let right = n - 1;
            while (left < right) {
                if (grid[row][left] !== grid[row][right]) {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        }
        const isColPalindrome = (col) => {
            let top = 0;
            let bottom = m - 1;
            while (top < bottom) {
                if (grid[top][col] !== grid[bottom][col]) {
                    return false;
                }
                top++;
                bottom--;
            }
            return true;
        }
        return isRowPalindrome(row) || isColPalindrome(col);
    }
    const flip = (row, col) => {
        grid[row][col] = 1 - grid[row][col];
    }
    const isAllPalindrome = () => {
        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                if (!isPalindrome(i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
    const dfs = (row, col, flips) => {
        if (isAllPalindrome()) {
            return flips;
        }
        if (row === m) {
            return Infinity;
        }
        const nextRow = col === n - 1 ? row + 1 : row;
        const nextCol = (col + 1) % n;
        const flipResult = dfs(nextRow, nextCol, flips + 1);
        flip(row, col);
        const noFlipResult = dfs(nextRow, nextCol, flips);
        flip(row, col);
        return Math.min(flipResult, noFlipResult);
    }
    const result = dfs(0, 0, 0);
    return result === Infinity ? -1 : result;
            
};