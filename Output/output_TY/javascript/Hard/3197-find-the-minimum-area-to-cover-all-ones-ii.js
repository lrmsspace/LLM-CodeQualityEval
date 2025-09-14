/*
 You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.
 Return the minimum possible sum of the area of these rectangles.
 Note that the rectangles are allowed to touch.
 Example 1:
 Input: grid = [[1,0,1],[1,1,1]]
 Output: 5
 Explanation:
 The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
 The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
 The 1 at (1, 1) is covered by a rectangle of area 1.
 Example 2:
 Input: grid = [[1,0,1,0],[0,1,0,1]]
 Output: 5
 Explanation:
 The 1's at (0, 0) and (0, 2) are covered by a rectangle of area 3.
 The 1 at (1, 1) is covered by a rectangle of area 1.
 The 1 at (1, 3) is covered by a rectangle of area 1.
 Constraints:
 1 <= grid.length, grid[i].length <= 30
 grid[i][j] is either 0 or 1.
 The input is generated such that there are at least three 1's in grid.
*/

/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumSum = function(grid) {
    let m = grid.length, n = grid[0].length;
    let dp = new Array(m).fill(0).map(() => new Array(n).fill(Infinity));
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
    return dp[n - 1][n - 1];
    
};