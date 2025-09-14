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
    const m = grid.length;
    const n = grid[0].length;
    const row = new Array(m).fill(0).map(() => new Array(n).fill(Infinity));
    const col = new Array(m).fill(0).map(() => new Array(n).fill(Infinity));
    const q = [];
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i + j > 0) {
                row[i][j] = Math.min(row[i][j], row[i - 1][j - 1] + 1);
                col[i][j] = Math.min(col[i][j], col[i - 1][j - 1] + 1);
            }
        }
    }
    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            if (i + j < m + n - 2) {
                row[i][j] = Math.min(row[i][j], row[i + 1][j + 1] + 1);
                col[i][j] = Math.min(col[i][j], col[i + 1][j + 1] + 1);
            }
            if (row[i][j] <= k && col[i][j] <= k) {
                q.push([i, j]);
            }
        }
    }
    while (q.length) {
        let [i, j] = q.shift();
        if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
            return true;
        }
        if (i + 1 < m && row[i + 1][j] == k && col[i + 1][j] == k) {
            q.push([i + 1, j]);
        }
        if (j + 1 < n && row[i][j + 1] == k && col[i][j + 1] == k) {
            q.push([i, j + 1]);
        }
    }
    return false;
};