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
    let dp = new Array(m).fill().map(() => new Array(n).fill().map(() => new Array(maxMove + 1).fill(0)));
    dp[startRow][startColumn][0] = 1;
    for (let i = 1; i <= maxMove; i++) {
        for (let j = 0; j < m; j++) {
            for (let k = 0; k < n; k++) {
                dp[j][k][i] = (dp[j][k][i] + (j > 0 ? dp[j - 1][k][i - 1] : 1)) % 1000000007;
                dp[j][k][i] = (dp[j][k][i] + (j < m - 1 ? dp[j + 1][k][i - 1] : 1))
                % 1000000007;
            }
        }
    }
    return dp.reduce((acc, cur) => acc + cur.reduce((acc, cur) => acc + cur[maxMove], 0), 0) - 4 * m * n;
};