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
int closedIsland(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize, cols = *gridColSize;
    int closedIslands = 0;
    
    // Iterate over each cell in the grid
    for (int r = 1; r < rows - 1; r++) {
        for (int c = 1; c < cols - 1; c++) {
            // If current cell is an island (0) and it's not surrounded by water (1s),
            // then it's a closed island
            if (grid[r][c] == 0 &&!isSurroundedByWater(grid, r, c, rows, cols)) {
                // Mark the island as closed by marking all its adjacent cells as 1
                markIsland(grid, r, c, rows, cols);
                closedIslands++;
            }
        }
    }
    
    return closedIslands;
    
}