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
    const directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    const island1 = findIsland(grid, 0, 0);
    const island2 = findIsland(grid, 0, 0, island1);
    
    let minSteps = Infinity;
    const queue = new Set([...island1]);
    
    while (queue.size) {
        const size = queue.size;
        for (let _ = 0; _ < size; _++) {
            const [x, y] = Array.from(queue.values()).next().value;
            queue.delete([x, y]);
            
            for (const [dx, dy] of directions) {
                const nx = x + dx;
                const ny = y + dy;
                
                if (nx < 0 || nx >= grid.length || ny < 0 || ny >= grid[0].length) continue;
                if (grid[nx][ny] === 1) continue;
                
                if (island2.has([nx, ny])) {
                    minSteps = Math.min(minSteps, getSteps(x, y, nx, ny));
                }
                
                queue.add([nx, ny]);
            }
        }
    }
    
    return minSteps;
    
};