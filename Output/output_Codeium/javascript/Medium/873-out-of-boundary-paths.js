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
    const MOD = 1e9 + 7;
    const dp = Array.from({length: maxMove + 1}, () => Array(m).fill(0).map(() => Array(n).fill(0)));
    for (let k = 1; k <= maxMove; k++) {
        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                if (i === 0) dp[k][i][j] += dp[k - 1][i + 1][j];
                if (i === m - 1) dp[k][i][j] += dp[k - 1][i - 1][j];
                if (j === 0) dp[k][i][j] += dp[k - 1][i][j + 1];
                if (j === n - 1) dp[k][i][j] += dp[k - 1][i][j - 1];
                dp[k][i][j] %= MOD;
            }
        }
    }
    return dp[maxMove][startRow][startColumn];
};