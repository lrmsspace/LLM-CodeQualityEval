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
    const parent = Array.from({ length: n * n * 4 }, (_, i) => i);
    
    const find = (x) => {
        if (parent[x] !== x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    };
    
    const union = (x, y) => {
        const rootX = find(x);
        const rootY = find(y);
        if (rootX !== rootY) {
            parent[rootX] = rootY;
        }
    };
    
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            const idx = (i * n + j) * 4;
            if (grid[i][j] === '/') {
                union(idx, idx + 3);
                union(idx + 1, idx + 2);
            } else if (grid[i][j] === '\\') {
                union(idx, idx + 1);
                union(idx + 2, idx + 3);
            } else {
                union(idx, idx + 1);
                union(idx + 1, idx + 2);
                union(idx + 2, idx + 3);
            }
            if (i > 0) {
                union(idx, ((i - 1) * n + j) * 4 + 2);
            }
            if (j > 0) {
                union(idx + 3, (i * n + j - 1) * 4 + 1);
            }
        }
    }
    
    const regions = new Set();
    for (let i = 0; i < n * n * 4; i++) {
        regions.add(find(i));
    }
    
    return regions.size;    
};