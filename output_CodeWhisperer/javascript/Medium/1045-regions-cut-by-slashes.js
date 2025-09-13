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
    let n = grid.length;
    let m = n * 3;
    let g = new Array(m).fill(0).map(() => new Array(m).fill(0));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] == '/') {
                g[i * 3][j * 3 + 2] = 1;
                g[i * 3 + 1][j * 3 + 1] = 1;
                g[i * 3 + 2][j * 3] = 1;
            } else if (grid[i][j] == '\\') {
                g[i * 3][j * 3] = 1;
                g[i * 3 + 1][j * 3 + 1] = 1;
                g[i * 3 + 2][j * 3 + 2] = 1;
            }
        }
    }
    let count = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < m; j++) {
            if (g[i][j] == 0) {
                count++;
                let q = [[i, j]];
                while (q.length > 0) {
                    let [x, y] = q.shift();
                    if (x < 0 || x >= m || y < 0 || y >= m || g[x][y] == 1) {
                        continue;
                    }
                    g[x][y] = 1;
                    q.push([x - 1, y]);
                    q.push([x + 1, y]);
                    q.push([x, y - 1]);
                    q.push([x, y + 1]);
                }
            }
        }
    }
    return count;
};