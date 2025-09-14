/**https://leetcode.com/problems/painting-a-grid-with-three-different-colors/ */
//You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.
//Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: m = 1, n = 1
//Output: 3
//Explanation: The three possible colorings are shown in the image above.
//Example 2:
//Input: m = 1, n = 2
//Output: 6
//Explanation: The six possible colorings are shown in the image above.
//Example 3:
//Input: m = 5, n = 5
//Output: 580986
// 
//Constraints:
//	1 <= m <= 5
//	1 <= n <= 1000
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var colorTheGrid = function(m, n) {
    const MOD = 1e9 + 7;
    const grid = new Array(n).fill(0).map(() => new Array(m).fill(0));
    const dp = new Array(n).fill(0).map(() => new Array(3 ** m).fill(0));
    dp[0][0] = 1;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < 3 ** m; j++) {
            if (dp[i][j] === 0) continue;
            for (let k = 0; k < m; k++) {
                if (grid[i][k] !== 0) continue;
                for (let l = 0; l < 3; l++) {
                    if (j & (1 << k) || l === 0) continue;
                    dp[i + 1][j | (1 << k)] += dp[i][j];
                    dp[i + 1][j | (1 << k)] %= MOD;
                }
            }
        }
    }
    return dp[n][0];
};