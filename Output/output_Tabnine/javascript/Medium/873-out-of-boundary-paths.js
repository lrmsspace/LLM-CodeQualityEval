/**https://leetcode.com/problems/out-of-boundary-paths/ */
//There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
//Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
//Output: 6
//Example 2:
//Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
//Output: 12
// 
//Constraints:
//	1 <= m, n <= 50
//	0 <= maxMove <= 50
//	0 <= startRow < m
//	0 <= startColumn < n
/**
 * @param {number} m
 * @param {number} n
 * @param {number} maxMove
 * @param {number} startRow
 * @param {number} startColumn
 * @return {number}
 */
var findPaths = function(m, n, maxMove, startRow, startColumn) {
    const MOD = 10 ** 9 + 7;
    const dp = Array.from({ length: m }, () => Array.from({ length: n }, () => Array(maxMove + 1).fill(0)));
    
    // Initialize the first row and column
    for (let i = 0; i <= maxMove; i++) {
        dp[0][0][i] = 1;
        dp[m - 1][n - 1][i] = 1;
        dp[0][n - 1][i] = 1;
        dp[m - 1][0][i] = 1;
    }
    
    // Fill the dp table
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            for (let k = 1; k <= maxMove; k++) {
                for (let x = -1; x <= 1; x++) {
                    for (let y = -1; y <= 1; y++) {
                        if (Math.abs(x) + Math.abs(y) === 1) {
                            dp[i][j][k] = (dp[i][j][k] + dp[i + x][j + y][k - 1]) % MOD;
                        }
                    }
                }
            }
        }
    }
    
    return dp[startRow][startColumn].reduce((acc, curr) => acc + curr, 0) % MOD;
    
};