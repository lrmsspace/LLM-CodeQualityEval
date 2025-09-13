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
    let m = grid.length, n = grid[0].length;
    let left = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    let up = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    let maxBorder = 0;
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (grid[i - 1][j - 1] == 1) {
                left[i][j] = left[i][j - 1] + 1;
                up[i][j] = up[i - 1][j] + 1;
                let border = Math.min(left[i][j], up[i][j]);
                while (left[i - border + 1][j] < border || up[i][j - border + 1] < border) {
                    border--;
                }
                maxBorder = Math.max(maxBorder, border);
            }
        }
    }
    return maxBorder * maxBorder;
};