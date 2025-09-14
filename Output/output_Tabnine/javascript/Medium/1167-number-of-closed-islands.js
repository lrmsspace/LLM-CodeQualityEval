/**https://leetcode.com/problems/number-of-closed-islands/ */
//Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
//Return the number of closed islands.
// 
//Example 1:
//Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
//Output: 2
//Explanation: 
//Islands in gray are closed because they are completely surrounded by water (group of 1s).
//Example 2:
//Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
//Output: 1
//Example 3:
//Input: grid = [[1,1,1,1,1,1,1],
//               [1,0,0,0,0,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,1,0,1,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,0,0,0,0,1],
//               [1,1,1,1,1,1,1]]
//Output: 2
// 
//Constraints:
//	1 <= grid.length, grid[0].length <= 100
//	0 <= grid[i][j] <=1
/**
 * @param {number[][]} grid
 * @return {number}
 */
var closedIsland = function(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    
    const dfs = (row, col) => {
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] === 1) return;
        
        grid[row][col] = 1; // Mark as visited
        
        dfs(row - 1, col); // Explore up
        dfs(row + 1, col); // Explore down
        dfs(row, col - 1); // Explore left
        dfs(row, col + 1); // Explore right
    };
    
    let closedIslandsCount = 0;
    
    for (let row = 0; row < rows; row++) {
        for (let col = 0; col < cols; col++) {
            if (grid[row][col] === 0) {
                dfs(row, col); // Start DFS from a closed island
                closedIslandsCount++; // Increment count of closed islands
            }
        }
    }
    
    return closedIslandsCount;
    
};