/**https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/ */
//You are given a 0-indexed m x n matrix grid consisting of positive integers.
//You can start at any cell in the first column of the matrix, and traverse the grid in the following way:
//	From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
//Return the maximum number of moves that you can perform.
// 
//Example 1:
//Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
//Output: 3
//Explanation: We can start at the cell (0, 0) and make the following moves:
//- (0, 0) -> (0, 1).
//- (0, 1) -> (1, 2).
//- (1, 2) -> (2, 3).
//It can be shown that it is the maximum number of moves that can be made.
//Example 2:
//Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
//Output: 0
//Explanation: Starting from any cell in the first column we cannot perform any moves.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	2 <= m, n <= 1000
//	4 <= m * n <= 105
//	1 <= grid[i][j] <= 106
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxMoves = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    const dp = Array.from({length: m}, () => Array(n).fill(0));
    let maxMoves = 0;
    
    for (let i = 0; i < m; i++) {
        for (let j = 1; j < n; j++) {
            dp[i][j] = Math.max(dp[i][j], grid[i][j] - grid[i][j - 1]);
            maxMoves = Math.max(maxMoves, dp[i][j]);
        }
    }
    
    for (let j = 0; j < n; j++) {
        for (let i = 1; i < m; i++) {
            dp[i][j] = Math.max(dp[i][j], grid[i][j] - grid[i - 1][j]);
            maxMoves = Math.max(maxMoves, dp[i][j]);
        }
    }
    
    return maxMoves * 2; // Since we can move in both directions (up and right) from each cell, we multiply by 2.
    
};