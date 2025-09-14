/*
 You are given a 2D integer array grid with size m x n. You are also given an integer k.
 Your task is to calculate the number of paths you can take from the top-left cell (0, 0) to the bottom-right cell (m - 1, n - 1) satisfying the following constraints:
 You can either move to the right or down. Formally, from the cell (i, j) you may move to the cell (i, j + 1) or to the cell (i + 1, j) if the target cell exists.
 The XOR of all the numbers on the path must be equal to k.
 Return the total number of such paths.
 Since the answer can be very large, return the result modulo 109 + 7.
 Example 1:
 Input: grid = [[2, 1, 5], [7, 10, 0], [12, 6, 4]], k = 11
 Output: 3
 Explanation: 
 The 3 paths are:
 (0, 0) → (1, 0) → (2, 0) → (2, 1) → (2, 2)
 (0, 0) → (1, 0) → (1, 1) → (1, 2) → (2, 2)
 (0, 0) → (0, 1) → (1, 1) → (2, 1) → (2, 2)
 Example 2:
 Input: grid = [[1, 3, 3, 3], [0, 3, 3, 2], [3, 0, 1, 1]], k = 2
 Output: 5
 Explanation:
 The 5 paths are:
 (0, 0) → (1, 0) → (2, 0) → (2, 1) → (2, 2) → (2, 3)
 (0, 0) → (1, 0) → (1, 1) → (2, 1) → (2, 2) → (2, 3)
 (0, 0) → (1, 0) → (1, 1) → (1, 2) → (1, 3) → (2, 3)
 (0, 0) → (0, 1) → (1, 1) → (1, 2) → (2, 2) → (2, 3)
 (0, 0) → (0, 1) → (0, 2) → (1, 2) → (2, 2) → (2, 3)
 Example 3:
 Input: grid = [[1, 1, 1, 2], [3, 0, 3, 2], [3, 0, 2, 2]], k = 10
 Output: 0
 Constraints:
 1 <= m == grid.length <= 300
 1 <= n == grid[r].length <= 300
 0 <= grid[r][c] < 16
 0 <= k < 16
*/

/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var countPathsWithXorValue = function(grid, k) {
    const MOD = 1e9 + 7;
    const m = grid.length;
    const n = grid[0].length;
    
    // Create a 3D DP array to store the number of paths with a given XOR value
    const dp = Array.from({ length: m }, () => Array.from({ length: n }, () => Array(16).fill(0)));
    
    // Initialize the starting point
    dp[0][0][grid[0][0]] = 1;
    
    // Fill the DP table
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            for (let x = 0; x < 16; x++) {
                if (dp[i][j][x] > 0) {
                    // Move right
                    if (j + 1 < n) {
                        dp[i][j + 1][x ^ grid[i][j + 1]] = (dp[i][j + 1][x ^ grid[i][j + 1]] + dp[i][j][x]) % MOD;
                    }
                    // Move down
                    if (i + 1 < m) {
                        dp[i + 1][j][x ^ grid[i + 1][j]] = (dp[i + 1][j][x ^ grid[i + 1][j]] + dp[i][j][x]) % MOD;
                    }
                }
            }
        }
    }
    
    // Return the number of paths that end at the bottom-right corner with XOR equal to k
    return dp[m - 1][n - 1][k];
        
};