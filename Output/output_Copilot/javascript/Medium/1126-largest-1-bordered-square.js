/**https://leetcode.com/problems/largest-1-bordered-square/ */
//Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.
// 
//Example 1:
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
//Output: 9
//Example 2:
//Input: grid = [[1,1,0,0]]
//Output: 1
// 
//Constraints:
//	1 <= grid.length <= 100
//	1 <= grid[0].length <= 100
//	grid[i][j] is 0 or 1
/**
 * @param {number[][]} grid
 * @return {number}
 */
var largest1BorderedSquare = function(grid) {
    const m = grid.length, n = grid[0].length;
    const dp = Array.from({ length: m }, () => Array(n).fill(0));
    let maxSize = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                dp[i][j] = Math.min(i > 0 ? dp[i - 1][j] : 0, j > 0 ? dp[i][j - 1] : 0) + 1;
                for (let size = dp[i][j]; size > maxSize; size--) {
                    if (i - size + 1 >= 0 && j - size + 1 >= 0 && grid[i][j - size + 1] === 1 && grid[i - size + 1][j] === 1) {
                        maxSize = Math.max(maxSize, size * size);
                    }
                }
            }
        }
    }

    return maxSize;  
};