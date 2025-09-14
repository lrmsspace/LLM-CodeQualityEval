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
    let dp = new Array(m).fill(0).map(() => new Array(n).fill(0));
    let mod = 1000000007;
    let directions = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    let ans = 0;
    dp[startRow][startColumn] = 1;
    for (let i = 0; i < maxMove; i++) {
        let temp = new Array(m).fill(0).map(() => new Array(n).fill(0));
        for (let j = 0; j < m; j++) {
            for (let k = 0; k < n; k++) {
                for (let direction of directions) {
                    let x = j + direction[0];
                    let y = k + direction[1];
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        ans = (ans + dp[j][k]) % mod;
                    } else {
                        temp[x][y] = (temp[x][y] + dp[j][k]) % mod;
                    }
                }
            }
        }
        dp = temp;
    }
    return ans;
};