/**https://leetcode.com/problems/coloring-a-border/ */
//You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location.
//Two squares are called adjacent if they are next to each other in any of the 4 directions.
//Two squares belong to the same connected component if they have the same color and they are adjacent.
//The border of a connected component is all the squares in the connected component that are either adjacent to (at least) a square not in the component, or on the boundary of the grid (the first or last row or column).
//You should color the border of the connected component that contains the square grid[row][col] with color.
//Return the final grid.
// 
//Example 1:
//Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
//Output: [[3,3],[3,2]]
//Example 2:
//Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
//Output: [[1,3,3],[2,3,3]]
//Example 3:
//Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
//Output: [[2,2,2],[2,1,2],[2,2,2]]
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	1 <= grid[i][j], color <= 1000
//	0 <= row < m
//	0 <= col < n
/**
 * @param {number[][]} grid
 * @param {number} row
 * @param {number} col
 * @param {number} color
 * @return {number[][]}
 */
var colorBorder = function(grid, row, col, color) {
    const m = grid.length;
    const n = grid[0].length;
    const originalColor = grid[row][col];
    const visited = Array.from({ length: m }, () => Array(n).fill(false));
    const border = new Set();

    function dfs(r, c) {
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || grid[r][c] !== originalColor) {
            return;
        }
        visited[r][c] = true;
        let isBorder = false;

        for (const [dr, dc] of [[-1, 0], [1, 0], [0, -1], [0, 1]]) {
            const nr = r + dr;
            const nc = c + dc;
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                isBorder = true; // Out of bounds
            } else if (grid[nr][nc] !== originalColor) {
                isBorder = true; // Adjacent to a different color
            } else if (!visited[nr][nc]) {
                dfs(nr, nc);
            }
        }

        if (isBorder) {
            border.add(`${r},${c}`);
        }
    }

    dfs(row, col);

    for (const b of border) {
        const [r, c] = b.split(',').map(Number);
        grid[r][c] = color;
    }

    return grid;    
};