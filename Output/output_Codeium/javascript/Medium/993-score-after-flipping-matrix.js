/**https://leetcode.com/problems/score-after-flipping-matrix/ */
//You are given an m x n binary matrix grid.
//A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
//Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
//Return the highest possible score after making any number of moves (including zero moves).
// 
//Example 1:
//Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
//Output: 39
//Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
//Example 2:
//Input: grid = [[0]]
//Output: 1
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 20
//	grid[i][j] is either 0 or 1.
/**
 * @param {number[][]} grid
 * @return {number}
 */
var matrixScore = function(grid) {
    let m = grid.length, n = grid[0].length, res = 0;
    // flip rows
    for (let i = 0; i < m; i++) {
        if (grid[i][0] === 0) {
            for (let j = 0; j < n; j++) {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }
    // flip columns
    for (let j = 1; j < n; j++) {
        let cnt = 0;
        for (let i = 0; i < m; i++) {
            cnt += grid[i][j];
        }
        if (cnt <= m / 2) {
            for (let i = 0; i < m; i++) {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }
    // calculate score
    for (let i = 0; i < m; i++) {
        let cur = 0;
        for (let j = 0; j < n; j++) {
            cur += grid[i][n - 1 - j] * (1 << j);
        }
        res += cur;
    }
    return res;
};