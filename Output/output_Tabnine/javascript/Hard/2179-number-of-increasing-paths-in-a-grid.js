/**https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/ */
//You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.
//Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.
//Two paths are considered different if they do not have exactly the same sequence of visited cells.
// 
//Example 1:
//Input: grid = [[1,1],[3,4]]
//Output: 8
//Explanation: The strictly increasing paths are:
//- Paths with length 1: [1], [1], [3], [4].
//- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
//- Paths with length 3: [1 -> 3 -> 4].
//The total number of paths is 4 + 3 + 1 = 8.
//Example 2:
//Input: grid = [[1],[2]]
//Output: 3
//Explanation: The strictly increasing paths are:
//- Paths with length 1: [1], [2].
//- Paths with length 2: [1 -> 2].
//The total number of paths is 2 + 1 = 3.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 1000
//	1 <= m * n <= 105
//	1 <= grid[i][j] <= 105
/**
 * @param {number[][]} grid
 * @return {number}
 */
var countPaths = function(grid) {
    const MOD = 1e9 + 7;
    const m = grid.length;
    const n = grid[0].length;
    const dp = Array.from({ length: m }, () => Array.from({ length: n }, () => Array(n+1).fill(0)));
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            for (let k = j + 1; k <= n; k++) {
                if (k === j + 1) {
                    dp[i][j][k] = 1;
                } else {
                    for (let l = j; l < k; l++) {
                        if (grid[i][l] < grid[i][k - 1]) {
                            dp[i][j][k] = (dp[i][j][k] + dp[i][l][k - 1]) % MOD;
                        }
                    }
                }
            }
        }

        for (let j = 0; j < n; j++) {
            for (let k = j + 1; k <= n; k++) {
                dp[i][k][n] = (dp[i][k][n] + dp[i][j][k]) % MOD;
            }
        }
    }
    
    let totalPaths = 0;
    for (let j = 0; j < n; j++) {
        totalPaths = (totalPaths + dp[m - 1][j][n]) % MOD;
    }
    
    return totalPaths;
};