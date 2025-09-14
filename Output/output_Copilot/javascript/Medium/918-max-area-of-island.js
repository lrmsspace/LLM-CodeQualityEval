/**https://leetcode.com/problems/max-area-of-island/ */
//You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//The area of an island is the number of cells with a value 1 in the island.
//Return the maximum area of an island in grid. If there is no island, return 0.
// 
//Example 1:
//Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
//Output: 6
//Explanation: The answer is not 11, because the island must be connected 4-directionally.
//Example 2:
//Input: grid = [[0,0,0,0,0,0,0,0]]
//Output: 0
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	grid[i][j] is either 0 or 1.
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    let maxArea = 0;
    const rows = grid.length;
    const cols = grid[0].length;

    function dfs(r, c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] === 0) {
            return 0;
        }
        grid[r][c] = 0; // Mark the cell as visited
        let area = 1; // Count this cell
        area += dfs(r + 1, c); // Down
        area += dfs(r - 1, c); // Up
        area += dfs(r, c + 1); // Right
        area += dfs(r, c - 1); // Left
        return area;
    }

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (grid[i][j] === 1) {
                maxArea = Math.max(maxArea, dfs(i, j));
            }
        }
    }

    return maxArea;    
};