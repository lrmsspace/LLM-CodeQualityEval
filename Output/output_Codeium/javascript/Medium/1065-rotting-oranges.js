/**https://leetcode.com/problems/rotting-oranges/ */
//You are given an m x n grid where each cell can have one of three values:
//	0 representing an empty cell,
//	1 representing a fresh orange, or
//	2 representing a rotten orange.
//Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
//Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
// 
//Example 1:
//Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
//Output: 4
//Example 2:
//Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
//Output: -1
//Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
//Example 3:
//Input: grid = [[0,2]]
//Output: 0
//Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 10
//	grid[i][j] is 0, 1, or 2.
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    const fresh = [];
    let minutes = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                fresh.push([i, j]);
            }
        }
    }
    const directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    while (fresh.length) {
        let len = fresh.length;
        for (let i = 0; i < len; i++) {
            const [x, y] = fresh.shift();
            for (const direction of directions) {
                const nx = x + direction[0];
                const ny = y + direction[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] === 2) {
                    grid[x][y] = 2;
                    break;
                }
            }
        }
        if (fresh.length === len) {
            return -1;
        }
        minutes++;
    }
    return minutes;
};