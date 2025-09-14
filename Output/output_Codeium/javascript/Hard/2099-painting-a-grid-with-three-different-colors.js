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
    let dp = Array.from({length: m}, () => Array(n).fill(0));
    dp[0][0] = 6;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i-1][j] * 3) % MOD;
            if (j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i][j-1] * 3) % MOD;
        }
    }
    return dp[m-1][n-1];
};