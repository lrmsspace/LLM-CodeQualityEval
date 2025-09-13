/**https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/ */
//You are given a 0-indexed m x n binary matrix grid. You can move from a cell (row, col) to any of the cells (row + 1, col) or (row, col + 1) that has the value 1. The matrix is disconnected if there is no path from (0, 0) to (m - 1, n - 1).
//You can flip the value of at most one (possibly none) cell. You cannot flip the cells (0, 0) and (m - 1, n - 1).
//Return true if it is possible to make the matrix disconnect or false otherwise.
//Note that flipping a cell changes its value from 0 to 1 or from 1 to 0.
// 
//Example 1:
//Input: grid = [[1,1,1],[1,0,0],[1,1,1]]
//Output: true
//Explanation: We can change the cell shown in the diagram above. There is no path from (0, 0) to (2, 2) in the resulting grid.
//Example 2:
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
//Output: false
//Explanation: It is not possible to change at most one cell such that there is not path from (0, 0) to (2, 2).
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 1000
//	1 <= m * n <= 105
//	grid[i][j] is either 0 or 1.
//	grid[0][0] == grid[m - 1][n - 1] == 1
/**
 * @param {number[][]} grid
 * @return {boolean}
 */
var isPossibleToCutPath = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    
    // Count the number of ones in the grid
    let onesCount = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) onesCount++;
        }
    }
    
    // If there are only two ones, they cannot be connected by flipping one cell
    if (onesCount === 2) return false;
    
    // Initialize a 2D array to store the minimum number of flips needed for each cell
    const dp = Array.from({ length: m }, () => Array.from({ length: n }, () => Infinity));
    
    // Initialize the base cases
    dp[0][0] = dp[m - 1][n - 1] = 0;
    
    // Iterate through the grid and calculate the minimum number of flips needed for each cell
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            if (grid[i][j] === 0) {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }
    
    // If the minimum number of flips needed is odd, it is impossible to make the matrix disconnect
    return dp[m - 1][n - 1] % 2 === 0;
    
};