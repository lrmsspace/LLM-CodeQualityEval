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
    int dfs(int** grid, int i, int j, int gridSize, int gridColSize) {
        if (i < 0 || j < 0 || i >= gridSize || j >= gridColSize) {
            return 0; // Reached boundary, not closed
        }
        if (grid[i][j] == 1) {
            return 1; // Water, continue
        }
        grid[i][j] = 1; // Mark as visited
        int top = dfs(grid, i - 1, j, gridSize, gridColSize);
        int bottom = dfs(grid, i + 1, j, gridSize, gridColSize);
        int left = dfs(grid, i, j - 1, gridSize, gridColSize);
        int right = dfs(grid, i, j + 1, gridSize, gridColSize);
        return top & bottom & left & right; // All directions must be closed
    }

    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 0) { // Found land
                count += dfs(grid, i, j, gridSize, gridColSize[0]);
            }
        }
    }   
    return count;
}