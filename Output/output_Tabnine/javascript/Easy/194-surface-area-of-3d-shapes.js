/**https://leetcode.com/problems/surface-area-of-3d-shapes/ */
//You are given an n x n grid where you have placed some 1 x 1 x 1 cubes. Each value v = grid[i][j] represents a tower of v cubes placed on top of cell (i, j).
//After placing these cubes, you have decided to glue any directly adjacent cubes to each other, forming several irregular 3D shapes.
//Return the total surface area of the resulting shapes.
//Note: The bottom face of each shape counts toward its surface area.
// 
//Example 1:
//Input: grid = [[1,2],[3,4]]
//Output: 34
//Example 2:
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
//Output: 32
//Example 3:
//Input: grid = [[2,2,2],[2,1,2],[2,2,2]]
//Output: 46
// 
//Constraints:
//	n == grid.length == grid[i].length
//	1 <= n <= 50
//	0 <= grid[i][j] <= 50
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    let ans = 0;
    let n = grid.length;
    
    for (let i = 0; i < n; i++) {

        for (let j = 0; j < n; j++) {
            // Add the area of the bottom face
            ans += grid[i][j] * 4;
            
            // Subtract the area of the overlapping faces
            for (let k = 0; k < grid[i][j]; k++) {
                ans -= Math.min(grid[i][Math.max(0, j - 1)], grid[i][Math.min(n - 1, j + 1)]) + Math.min(grid[Math.max(0, i - 1)][j], grid[Math.min(n - 1, i + 1)][j]);
                ans -= Math.min(grid[i][j], grid[i][Math.max(0, k - 1)]);
            }
        }
    }
    
    return ans;
    
};