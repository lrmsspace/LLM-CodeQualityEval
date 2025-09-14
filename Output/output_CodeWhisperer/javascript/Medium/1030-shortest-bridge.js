/**https://leetcode.com/problems/shortest-bridge/ */
//You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
//An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
//You may change 0's to 1's to connect the two islands to form one island.
//Return the smallest number of 0's you must flip to connect the two islands.
// 
//Example 1:
//Input: grid = [[0,1],[1,0]]
//Output: 1
//Example 2:
//Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
//Output: 2
//Example 3:
//Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
//Output: 1
// 
//Constraints:
//	n == grid.length == grid[i].length
//	2 <= n <= 100
//	grid[i][j] is either 0 or 1.
//	There are exactly two islands in grid.
/**
 * @param {number[][]} grid
 * @return {number}
 */
var shortestBridge = function(grid) {
    const n = grid.length;
    const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    let found = false;
    let queue = [];
    for (let i = 0; i < n; i++) {
        if (found) break;
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                dfs(grid, i, j, queue);
                found = true;
                break;
            }
        }
    }
    let step = 0;
    while (queue.length) {
        let size = queue.length;
        while (size--) {
            let [i, j] = queue.shift();
            for (let [x, y] of dirs) {
                let nx = i + x, ny = j + y;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] === 2) continue;
                if (grid[nx][ny] === 1) return step;
                grid[nx][ny] = 2;
                queue.push([nx, ny]);
            }
        }
        step++;
    }
    return -1;

};