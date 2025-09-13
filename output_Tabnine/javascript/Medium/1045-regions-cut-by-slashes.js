/**https://leetcode.com/problems/regions-cut-by-slashes/ */
//An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.
//Given the grid grid represented as a string array, return the number of regions.
//Note that backslash characters are escaped, so a '\' is represented as '\\'.
// 
//Example 1:
//Input: grid = [" /","/ "]
//Output: 2
//Example 2:
//Input: grid = [" /","  "]
//Output: 1
//Example 3:
//Input: grid = ["/\\","\\/"]
//Output: 5
//Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
// 
//Constraints:
//	n == grid.length == grid[i].length
//	1 <= n <= 30
//	grid[i][j] is either '/', '\', or ' '.
/**
 * @param {string[]} grid
 * @return {number}
 */
var regionsBySlashes = function(grid) {
    const n = grid.length;
    const size = n * 3;
    const directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    const graph = Array.from({ length: size }, () => new Set());
    
    const addEdge = (x, y, dx, dy) => {
        const p1 = (x + dx) * 3 + dy;
        const p2 = (x * 3 + dx) + (y + dy) * 3;
        graph[p1].add(p2);
        graph[p2].add(p1);
    };
    
    const markRegion = (x, y, dx, dy) => {
        const p = (x * 3 + dx) + (y * 3 + dy) * 3;
        if (graph[p].size === 0) {
            graph[p].add(p);
            for (const [dx, dy] of directions) {
                markRegion(x + dx, y + dy, dx, dy);
            }
        }
    };
    
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === '/') {
                addEdge(i, j, 0, 1);
                addEdge(i, j, 1, 0);
            } else if (grid[i][j] === '\\') {
                addEdge(i, j, 0, 1);
                addEdge(i, j, 1, 0);
                addEdge(i, j, 0, 2);
                addEdge(i, j, 2, 0);
            } else {
                addEdge(i, j, 0, 1);
                addEdge(i, j, 1, 0);
                addEdge(i, j, 0, 2);
                addEdge(i, j, 2, 0);
            }
        }
    }
    
    markRegion(0, 0, 0, 0);
    
    return Array.from(graph[0]).length;
    
};