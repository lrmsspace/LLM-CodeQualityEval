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
    let n = grid.length;
    let queue = [];
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                queue.push([i, j]);
            }
        }
    }
    if (queue.length === 0 || queue.length === n * n) {
        return -1;
    }
    let distance = -1;
    while (queue.length > 0) {
        let size = queue.length;
        for (let i = 0; i < size; i++) {
            let [x, y] = queue.shift();
            if (x - 1 >= 0 && grid[x - 1][y] === 0) {
                grid[x - 1][y] = 1;
                queue.push([x - 1, y]);
            }
            if (x + 1 < n && grid[x + 1][y] === 0) {
                grid[x + 1][y] = 1;
                queue.push([x + 1, y]);
            }
            if (y - 1 >= 0 && grid[x][y - 1] === 0) {
                grid[x][y - 1] = 1;
                queue.push([x, y - 1]);
            }
            if (y + 1 < n && grid[x][y + 1] === 0) {
                grid[x][y + 1] = 1;
                queue.push([x, y + 1]);
            }
        }
        distance++;
    }
    return distance;
};