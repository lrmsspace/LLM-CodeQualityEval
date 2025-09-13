/**https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/ */
//You are given an m x n integer matrix grid and an array queries of size k.
//Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:
//	If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
//	Otherwise, you do not get any points, and you end this process.
//After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.
//Return the resulting array answer.
// 
//Example 1:
//Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
//Output: [5,8,1]
//Explanation: The diagrams above show which cells we visit to get points for each query.
//Example 2:
//Input: grid = [[5,2,1],[1,1,2]], queries = [3]
//Output: [0]
//Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	2 <= m, n <= 1000
//	4 <= m * n <= 105
//	k == queries.length
//	1 <= k <= 104
//	1 <= grid[i][j], queries[i] <= 106
/**
 * @param {number[][]} grid
 * @param {number[]} queries
 * @return {number[]}
 */
var maxPoints = function(grid, queries) {
    const m = grid.length;
    const n = grid[0].length;
    const dx = [-1, 0, 1, 0];
    const dy = [0, 1, 0, -1];
    const ans = [];
    for (let q of queries) {
        let vis = new Array(m).fill(0).map(() => new Array(n).fill(false));
        let cnt = 0;
        let x = 0, y = 0;
        while (true) {
            if (vis[x][y] || grid[x][y] >= q) break;
            vis[x][y] = true;
            cnt++;
            let nx = -1, ny = -1;
            for (let i = 0; i < 4; i++) {
                let tx = x + dx[i];
                let ty = y + dy[i];
                if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
                if (!vis[tx][ty] && grid[tx][ty] < q && (nx === -1 || grid[tx][ty] > grid[nx][ny])) {
                    nx = tx;
                    ny = ty;
                }
            }
            if (nx === -1) break;
            x = nx;
            y = ny;
        }
        ans.push(cnt);
    }
    return ans;
};