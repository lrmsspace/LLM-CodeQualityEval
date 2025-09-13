/**https://leetcode.com/problems/detect-cycles-in-2d-grid/ */
//Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.
//A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.
//Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.
//Return true if any cycle of the same value exists in grid, otherwise, return false.
// 
//Example 1:
//Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
//Output: true
//Explanation: There are two valid cycles shown in different colors in the image below:
//Example 2:
//Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
//Output: true
//Explanation: There is only one valid cycle highlighted in the image below:
//Example 3:
//Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
//Output: false
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 500
//	grid consists only of lowercase English letters.
/**
 * @param {character[][]} grid
 * @return {boolean}
 */
var containsCycle = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    const visited = new Array(m).fill(0).map(() => new Array(n).fill(false));
    
    const dfs = (i, j, parentI, parentJ, char) => {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] !== char) {
            return false;
        }
        if (visited[i][j]) {
            return true;
        }
        visited[i][j] = true;
        const directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];
        for (const [di, dj] of directions) {
            const ni = i + di;
            const nj = j + dj;
            if (ni !== parentI || nj !== parentJ) {
                if (dfs(ni, nj, i, j, char)) {
                    return true;
                }
            }
        }
        return false;
    };
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (!visited[i][j]) {
                if (dfs(i, j, -1, -1, grid[i][j])) {
                    return true;
                }
            }
        }
    }
    
    return false;
};