/**https://leetcode.com/problems/as-far-from-land-as-possible/ */
//Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.
//The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
// 
//Example 1:
//Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
//Output: 2
//Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
//Example 2:
//Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
//Output: 4
//Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 100
//	grid[i][j] is 0 or 1
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function(grid) {
    const n = grid.length;
    const queue = [];
    const directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    let maxDist = -1;

    // Initialize the queue with all land cells (1s)
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                queue.push([i, j]);
            }
        }
    }

    // If there are no land or water cells, return -1
    if (queue.length === 0 || queue.length === n * n) {
        return -1;
    }

    // BFS to find the maximum distance from land to water
    while (queue.length > 0) {
        const size = queue.length;
        maxDist++; // Increase distance at each level of BFS

        for (let i = 0; i < size; i++) {
            const [x, y] = queue.shift();

            for (const [dx, dy] of directions) {
                const newX = x + dx;
                const newY = y + dy;

                if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] === 0) {
                    grid[newX][newY] = 1; // Mark as visited
                    queue.push([newX, newY]); // Add to queue for further exploration
                }
            }
        }
    }

    return maxDist;    
};