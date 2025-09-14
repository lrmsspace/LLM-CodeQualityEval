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
    let n = grid.length;
    let directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    let queue = [];
    let visited = Array(n).fill(0).map(() => new Array(n).fill(false));
    let found = false;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                found = true;
                queue.push([i, j]);
                visited[i][j] = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    let step = 0;
    while (queue.length) {
        let size = queue.length;
        for (let k = 0; k < size; k++) {
            let [x, y] = queue.shift();
            for (let i = 0; i < 4; i++) {
                let nx = x + directions[i][0];
                let ny = y + directions[i][1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    if (grid[nx][ny] === 1) {
                        return step;
                    }
                    queue.push([nx, ny]);
                    visited[nx][ny] = true;
                }
            }
        }
        step++;
    }

    return step;
};