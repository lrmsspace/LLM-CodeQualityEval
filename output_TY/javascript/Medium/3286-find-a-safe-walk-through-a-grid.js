/*
 You are given an m x n binary matrix grid and an integer health.
 You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).
 You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.
 Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.
 Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.
 Example 1:
 Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1
 Output: true
 Explanation:
 The final cell can be reached safely by walking along the gray cells below.
 Example 2:
 Input: grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3
 Output: false
 Explanation:
 A minimum of 4 health points is needed to reach the final cell safely.
 Example 3:
 Input: grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5
 Output: true
 Explanation:
 The final cell can be reached safely by walking along the gray cells below.
 Any path that does not go through the cell (1, 1) is unsafe since your health will drop to 0 when reaching the final cell.
 Constraints:
 m == grid.length
 n == grid[i].length
 1 <= m, n <= 50
 2 <= m * n
 1 <= health <= m + n
 grid[i][j] is either 0 or 1.
*/

/**
 * @param {number[][]} grid
 * @param {number} health
 * @return {boolean}
 */
var findSafeWalk = function(grid, health) {

    let m = grid.length, n = grid[0].length;
    let dp = new Array(m).fill().map(() => new Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 && j === 0) {
                dp[i][j] = grid[i][j];
            } else if (i === 0) {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            } else if (j === 0) {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            } else {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[ i] [j];
            }
        }
    }
    return dp[m - 1][n - 1];
    
};