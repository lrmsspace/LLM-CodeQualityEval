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
    const m = grid.length, n = grid[0].length;
    const directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    let freshCount = 0, rottenCount = 0;
    const queue = [];

    // Count fresh oranges and enqueue rotten oranges
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) freshCount++;
            else if (grid[i][j] === 2) {
                queue.push([i, j]);
                rottenCount++;
            }
        }
    }

    if (freshCount === 0) return 0; // No fresh oranges to rot

    let minutes = 0;
    
    while (queue.length > 0 && freshCount > 0) {
        const size = queue.length;
        minutes++;
        
        for (let k = 0; k < size; k++) {
            const [x, y] = queue.shift();
            
            for (const [dx, dy] of directions) {
                const newX = x + dx, newY = y + dy;
                
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] === 1) {
                    grid[newX][newY] = 2; // Mark as rotten
                    queue.push([newX, newY]);
                    freshCount--;
                }
            }
        }
    }

    return freshCount === 0 ? minutes : -1; // Return -1 if there are still fresh oranges left    
};