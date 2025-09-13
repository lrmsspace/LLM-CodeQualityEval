/*
 You are given a 2D matrix grid of size n x n. Initially, all cells of the grid are colored white. In one operation, you can select any cell of indices (i, j), and color black all the cells of the jth column starting from the top row down to the ith row.
 The grid score is the sum of all grid[i][j] such that cell (i, j) is white and it has a horizontally adjacent black cell.
 Return the maximum score that can be achieved after some number of operations.
 Example 1:
 Input: grid = [[0,0,0,0,0],[0,0,3,0,0],[0,1,0,0,0],[5,0,0,3,0],[0,0,0,0,2]]
 Output: 11
 Explanation:
 In the first operation, we color all cells in column 1 down to row 3, and in the second operation, we color all cells in column 4 down to the last row. The score of the resulting grid is grid[3][0] + grid[1][2] + grid[3][3] which is equal to 11.
 Example 2:
 Input: grid = [[10,9,0,0,15],[7,1,0,8,0],[5,20,0,11,0],[0,0,0,1,2],[8,12,1,10,3]]
 Output: 94
 Explanation:
 We perform operations on 1, 2, and 3 down to rows 1, 4, and 0, respectively. The score of the resulting grid is grid[0][0] + grid[1][0] + grid[2][1] + grid[4][1] + grid[1][3] + grid[2][3] + grid[3][3] + grid[4][3] + grid[0][4] which is equal to 94.
 Constraints:
 1 <= n == grid.length <= 100
 n == grid[i].length
 0 <= grid[i][j] <= 109
*/

/**
 * @param {number[][]} grid
 * @return {number}
 */
var maximumScore = function(grid) {
    const n = grid.length;
    const m = grid[0].length;
    const dp = Array.from({ length: n }, () => Array.from({ length: m }, () => Array(2).fill(0)));  
    for (let i = 0; i < n; i++) {
        dp[i][0][0] = grid[i][0];
        for (let j = 1; j < m; j++) {
            dp[i][j][0] = grid[i][j] + Math.max(dp[i][j - 1][0], dp[i][j - 1][1]);
        }
    }
    for (let j = 1; j < m; j++) {
        dp[0][j][1] = grid[0][j] + Math.max(dp[0][j - 1][0], dp[0][j - 1][1]);
        for (let i = 1; i < n; i++) {
            dp[i][j][1] = grid[i][j] + Math.max(dp[i - 1][j][0], dp[i - 1][j][1], dp[i - 1][j - 1][0]);
        }
    }
    let maxScore = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            maxScore = Math.max(maxScore, dp[i][j][0] + dp[i][j][1]);
        }
    }
    return maxScore;
    
};