/**https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/ */
//You are given a 0-indexed m x n binary matrix grid. You can move from a cell (row, col) to any of the cells (row + 1, col) or (row, col + 1) that has the value 1. The matrix is disconnected if there is no path from (0, 0) to (m - 1, n - 1).
//You can flip the value of at most one (possibly none) cell. You cannot flip the cells (0, 0) and (m - 1, n - 1).
//Return true if it is possible to make the matrix disconnect or false otherwise.
//Note that flipping a cell changes its value from 0 to 1 or from 1 to 0.
// 
//Example 1:
//Input: grid = [[1,1,1],[1,0,0],[1,1,1]]
//Output: true
//Explanation: We can change the cell shown in the diagram above. There is no path from (0, 0) to (2, 2) in the resulting grid.
//Example 2:
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
//Output: false
//Explanation: It is not possible to change at most one cell such that there is not path from (0, 0) to (2, 2).
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 1000
//	1 <= m * n <= 105
//	grid[i][j] is either 0 or 1.
//	grid[0][0] == grid[m - 1][n - 1] == 1
/**
 * @param {number[][]} grid
 * @return {boolean}
 */
var isPossibleToCutPath = function(grid) {
    const m = grid.length, n = grid[0].length;
    const visited = Array.from({ length: m }, () => Array(n).fill(false));
    const directions = [[0, 1], [1, 0]];
    
    function dfs(x, y) {
        if (x === m - 1 && y === n - 1) return true;
        visited[x][y] = true;
        
        for (const [dx, dy] of directions) {
            const nx = x + dx, ny = y + dy;
            if (nx < m && ny < n && grid[nx][ny] === 1 && !visited[nx][ny]) {
                if (dfs(nx, ny)) return true;
            }
        }
        
        return false;
    }
    
    const canReachEnd = dfs(0, 0);
    
    if (!canReachEnd) return true; // Already disconnected
    
    visited.forEach(row => row.fill(false)); // Reset visited
    
    grid[0][0] = grid[m - 1][n - 1] = 0; // Temporarily block start and end
    
    const canReachEndAfterBlock = dfs(0, 0);
    
    grid[0][0] = grid[m - 1][n - 1] = 1; // Restore start and end
    
    return !canReachEndAfterBlock;    
};