/**https://leetcode.com/problems/largest-magic-square/ */
//A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.
//Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.
// 
//Example 1:
//Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
//Output: 3
//Explanation: The largest magic square has a size of 3.
//Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
//- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
//- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
//- Diagonal sums: 5+4+3 = 6+4+2 = 12
//Example 2:
//Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
//Output: 2
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	1 <= grid[i][j] <= 106
/**
 * @param {number[][]} grid
 * @return {number}
 */
var largestMagicSquare = function(grid) {
    let m = grid.length;
    let n = grid[0].length;
    let minMn = Math.min(m, n);
    for (let k = minMn; k >= 1; k--) {
        if (isMagic(grid, k)) {
            return k;
        }
    }
    return 1;
}

function isMagic(grid, k) {
    let rowSum = 0;
    for (let i = 0; i < k; i++) {
        rowSum += grid[0][i];
    }
    for (let i = 0; i < grid.length - k + 1; i++) {
        for (let j = 0; j < grid[0].length - k + 1; j++) {
            if (!isMagicSquare(grid, i, j, k, rowSum)) {
                return false;
            }
        }
    }
    return true;
}

function isMagicSquare(grid, r, c, k, target) {
    let rowSum = 0;
    for (let i = 0; i < k; i++) {
        rowSum += grid[r + i][c];
    }
    if (rowSum !== target) {
        return false;
    }
    for (let i = 0; i < k; i++) {
        let colSum = 0;
        for (let j = 0; j < k; j++) {
            colSum += grid[r + j][c + i];
        }
        if (colSum !== target) {
            return false;
        }
    }
    let leftDiagSum = 0;
    for (let i = 0; i < k; i++) {
        leftDiagSum += grid[r + i][c + i];
    }
    if (leftDiagSum !== target) {
        return false;
    }
    let rightDiagSum = 0;
    for (let i = 0; i < k; i++) {
        rightDiagSum += grid[r + i][c + k - 1 - i];
    }
    return rightDiagSum === target;
};