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
    const directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    let queue = [];
    let visited = new Set();

    // DFS to find the first island and mark it as visited
    const dfs = (i, j) => {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] === 0 || visited.has(`${i},${j}`)) return;
        visited.add(`${i},${j}`);
        queue.push([i, j]);
        for (const [dx, dy] of directions) {
            dfs(i + dx, j + dy);
        }
    };

    // Find the first island
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                dfs(i, j);
                break;
            }
        }
        if (queue.length > 0) break;
    }

    // BFS to find the shortest path to the second island
    let steps = 0;
    while (queue.length > 0) {
        const size = queue.length;
        for (let k = 0; k < size; k++) {
            const [x, y] = queue.shift();
            for (const [dx, dy] of directions) {
                const nx = x + dx;
                const ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (grid[nx][ny] === 1 && !visited.has(`${nx},${ny}`)) return steps;
                if (grid[nx][ny] === 0 && !visited.has(`${nx},${ny}`)) {
                    visited.add(`${nx},${ny}`);
                    queue.push([nx, ny]);
                }
            }
        }
        steps++;
    }

    return -1; // This line should never be reached    
};