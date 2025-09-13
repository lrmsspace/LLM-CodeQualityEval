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
    const MOD = 10 ** 9 + 7;
    const dp = Array(n + 1).fill(0);
    dp[0] = 1;
    
    for (let i = 1; i <= n; i++) {
        dp[i] = (dp[i - 1] * 3) % MOD;
    }
    
    for (let i = 2; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - 1] * 2) % MOD;
        }
    }
    
    return dp[n];
    
};