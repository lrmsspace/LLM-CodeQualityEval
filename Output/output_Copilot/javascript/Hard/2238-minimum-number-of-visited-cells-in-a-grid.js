/**https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/ */
//You are given a 0-indexed m x n integer matrix grid. Your initial position is at the top-left cell (0, 0).
//Starting from the cell (i, j), you can move to one of the following cells:
//	Cells (i, k) with j < k <= grid[i][j] + j (rightward movement), or
//	Cells (k, j) with i < k <= grid[i][j] + i (downward movement).
//Return the minimum number of cells you need to visit to reach the bottom-right cell (m - 1, n - 1). If there is no valid path, return -1.
// 
//Example 1:
//Input: grid = [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]
//Output: 4
//Explanation: The image above shows one of the paths that visits exactly 4 cells.
//Example 2:
//Input: grid = [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]
//Output: 3
//Explanation: The image above shows one of the paths that visits exactly 3 cells.
//Example 3:
//Input: grid = [[2,1,0],[1,0,0]]
//Output: -1
//Explanation: It can be proven that no path exists.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	0 <= grid[i][j] < m * n
//	grid[m - 1][n - 1] == 0
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumVisitedCells = function(grid) {
    const m = grid.length, n = grid[0].length;
    const dp = new Array(m).fill(0).map(() => new Array(n).fill(Infinity));
    dp[0][0] = 1;
    const queue = [[0, 0]];
    while (queue.length) {
        const [x, y] = queue.shift();
        for (let i = x + 1; i <= Math.min(x + grid[x][y], m - 1); i++) {
            if (dp[i][y] > dp[x][y] + 1) {
                dp[i][y] = dp[x][y] + 1;
                queue.push([i, y]);
            }
        }
        for (let j = y + 1; j <= Math.min(y + grid[x][y], n - 1); j++) {
            if (dp[x][j] > dp[x][y] + 1) {
                dp[x][j] = dp[x][y] + 1;
                queue.push([x, j]);
            }
        }
    }
    return dp[m - 1][n - 1] === Infinity ? -1 : dp[m - 1][n - 1];    
};