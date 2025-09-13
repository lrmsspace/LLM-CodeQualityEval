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
    const m = grid.length;
    const n = grid[0].length;
    const isPalindromic = (row) => {
        let left = 0;
        let right = row.length - 1;
        while (left < right) {
            if (row[left] !== row[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    };
    const flip = (row, col) => {
        const result = [];
        for (let i = 0; i < m; i++) {
            result.push([...grid[i]]);
        }
        for (let i = 0; i < m; i++) {
            result[i][col] = 1 - result[i][col];
        }
        for (let j = 0; j < n; j++) {
            result[row][j] = 1 - result[row][j];
        }
        return result;
    };
    const dfs = (grid) => {
        if (isPalindromic(grid.map(row => row.join('')))) {
            return 0;
        }
        let minFlips = Infinity;
        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                const flipped = flip(i, j);
                const flips = 1 + dfs(flipped);
                minFlips = Math.min(minFlips, flips);
            }
        }
        return minFlips;
    };
    return dfs(grid);    
};