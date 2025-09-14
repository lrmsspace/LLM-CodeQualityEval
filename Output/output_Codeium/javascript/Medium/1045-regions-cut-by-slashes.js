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
const graph = Array.from({ length: n * 3 }, () => Array(n * 3).fill(0));

for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
        if (grid[i][j] === '/') {
            graph[i * 3][j * 3 + 2] = 1;
            graph[i * 3 + 1][j * 3 + 1] = 1;
            graph[i * 3 + 2][j * 3] = 1;
        }
        if (grid[i][j] === '\\') {
            graph[i * 3][j * 3] = 1;
            graph[i * 3 + 1][j * 3 + 1] = 1;
            graph[i * 3 + 2][j * 3 + 2] = 1;
        }
    }
}

const dfs = (x, y) => {
    if (x >= 0 && x < n * 3 && y >= 0 && y < n * 3 && graph[x][y] === 0) {
        graph[x][y] = 1;
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y - 1);
        dfs(x, y + 1);
    }
};

let regions = 0;
for (let i = 0; i < n * 3; i++) {
    for (let j = 0; j < n * 3; j++) {
        if (graph[i][j] === 0) {
            regions++;
            dfs(i, j);
        }
    }
}

return regions;

};