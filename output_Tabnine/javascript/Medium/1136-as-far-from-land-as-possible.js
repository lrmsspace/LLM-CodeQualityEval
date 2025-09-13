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
    const m = grid.length;
    if (m === 0) return -1;
    const n = grid[0].length;
    const queue = [];
    let maxDistance = 0;
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                queue.push([i, j, 0]);
            }
        }
    }
    
    if (queue.length === 0) return -1;
    
    const directions = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    
    while (queue.length > 0) {
        const [x, y, distance] = queue.shift();
        
        if (distance > maxDistance) maxDistance = distance;
        
        for (const [dx, dy] of directions) {
            const newX = x + dx;
            const newY = y + dy;
            
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] === 0) {
                grid[newX][newY] = 1;
                queue.push([newX, newY, distance + 1]);
            }
        }
    }
    
    return maxDistance === 0? -1 : maxDistance;
    
};