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
    const m = grid.length;
    const n = grid[0].length;
    const dp = Array.from({ length: m }, () => Array.from({ length: n }, () => Array.from({ length: 2 }, () => Array.from({ length: 2 }, () => -Infinity))));
    dp[0][0][0][0] = grid[0][0] === 1? 1 : 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {   
            if (grid[i][j] === 1) {
                dp[i][j][0][0] = Math.max(dp[i][j][0][0], dp[i - 1][j][0][0] + 1);
                dp[i][j][0][1] = Math.max(dp[i][j][0][1], dp[i - 1][j][0][1] + 1);
                dp[i][j][1][0] = Math.max(dp[i][j][1][0], dp[i][j - 1][1][0] + 1);
                dp[i][j][1][1] = Math.max(dp[i][j][1][1], dp[i][j - 1][1][1] + 1);
            }   
            dp[i][j][0][0] = Math.max(dp[i][j][0][0], dp[i][j][0][1]);
            dp[i][j][1][0] = Math.max(dp[i][j][1][0], dp[i][j][1][1]);  
            dp[i][j][0][1] = dp[i][j][1][0] = 0;
            dp[i][j][1][1] = dp[i][j][0][0] + dp[i][j][0][1] + dp[i][j][1][0] + dp[i][j][1][1] - Math.min(dp[i][j][0][0], dp[i][j][0][1]) - Math.min(dp[i][j][1][0], dp[i][j][
                1][1]);
        }
        dp[i][0][0][1] = dp[i][0][1][0] = 0;    
        dp[i][0][1][1] = dp[i][0][0][0] + dp[i][0][0][1] + dp[i][0][1][0] + dp[i][0][1][1] - Math.min(dp[i][0][0][0], dp[i][0][0][1]) - Math.min(dp[i][0][1][0], dp[i][0][
            1][1]);
    }
    dp[0][0][0][1] = dp[0][0][1][0] = 0;
    dp[0][0][1][1] = dp[0][0][0][0] + dp[0][0][0][1] + dp[0][0][1][0] + dp[0][0][1][1] - Math.min(dp[0][0][0][0], dp[0][0][0][1]) - Math.min(dp[0][0][1][0], dp[0][0][  
        1][1]);
    return dp[m - 1][n - 1][1][1];


    
};