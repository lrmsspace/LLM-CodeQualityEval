/**https://leetcode.com/problems/stamping-the-grid/ */
//You are given an m x n binary matrix grid where each cell is either 0 (empty) or 1 (occupied).
//You are then given stamps of size stampHeight x stampWidth. We want to fit the stamps such that they follow the given restrictions and requirements:
//	Cover all the empty cells.
//	Do not cover any of the occupied cells.
//	We can put as many stamps as we want.
//	Stamps can overlap with each other.
//	Stamps are not allowed to be rotated.
//	Stamps must stay completely inside the grid.
//Return true if it is possible to fit the stamps while following the given restrictions and requirements. Otherwise, return false.
// 
//Example 1:
//Input: grid = [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]], stampHeight = 4, stampWidth = 3
//Output: true
//Explanation: We have two overlapping stamps (labeled 1 and 2 in the image) that are able to cover all the empty cells.
//Example 2:
//Input: grid = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], stampHeight = 2, stampWidth = 2 
//Output: false 
//Explanation: There is no way to fit the stamps onto all the empty cells without the stamps going outside the grid.
// 
//Constraints:
//	m == grid.length
//	n == grid[r].length
//	1 <= m, n <= 105
//	1 <= m * n <= 2 * 105
//	grid[r][c] is either 0 or 1.
//	1 <= stampHeight, stampWidth <= 105
/**
 * @param {number[][]} grid
 * @param {number} stampHeight
 * @param {number} stampWidth
 * @return {boolean}
 */
var possibleToStamp = function(grid, stampHeight, stampWidth) {
    let m = grid.length, n = grid[0].length;
    let dp = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0).map(() => new Array(stampHeight + 1).fill(0).map(() => new Array(stampWidth + 1).fill(0))));

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            for (let h = 1; h <= stampHeight; h++) {
                for (let w = 1; w <= stampWidth; w++) {
                    if (grid[i - 1][j - 1] == 0) {
                        dp[i][j][h][w] = 1 + Math.min(dp[i - 1][j][h - 1][w], Math.min(dp[i][j - 1][h][w - 1], dp[i - 1][j - 1][h - 1][w - 1]));
                    }
                }
            }
        }
    }

    for (let i = stampHeight - 1; i < m; i++) {
        for (let j = stampWidth - 1; j < n; j++) {
            let x = i - stampHeight + 1, y = j - stampWidth + 1;
            let sum = 0;
            for (let h = 1; h <= stampHeight; h++) {
                for (let w = 1; w <= stampWidth; w++) {
                    sum += dp[i - h + 1][j - w + 1][h][w];
                }
            }
            if (sum == stampHeight * stampWidth && grid[x][y] == 0) return true;
        }
    }
    return false;
};