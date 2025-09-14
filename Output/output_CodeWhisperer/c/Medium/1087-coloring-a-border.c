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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */ 
int** colorBorder(int** grid, int gridSize, int* gridColSize, int row, int col, int color, int* returnSize, int** returnColumnSizes) {
    // Create a copy of the grid to return
    int** result = (int**)malloc(gridSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(gridSize * sizeof(int));
    *returnSize = gridSize;
    
    for (int i = 0; i < gridSize; i++) {
        result[i] = (int*)malloc(gridColSize[i] * sizeof(int));
        (*returnColumnSizes)[i] = gridColSize[i];
        
        // Copy the original grid values
        for (int j = 0; j < gridColSize[i]; j++) {
            result[i][j] = grid[i][j];
        }
    }
    
    // Original color of the component
    int originalColor = grid[row][col];
    
    // If the original color is the same as the new color, no change needed
    if (originalColor == color) {
        return result;
    }
    
    // Create a visited array to keep track of visited cells
    int** visited = (int**)malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        visited[i] = (int*)calloc(gridColSize[i], sizeof(int));
    }
    
    // Directions for adjacent cells (up, right, down, left)
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    // DFS to find and color the border
    void dfs(int r, int c) {
        // Mark as visited
        visited[r][c] = 1;
        
        // Check if this cell is on the border
        int isBorder = 0;
        
        // Check if it's on the grid boundary
        if (r == 0 || r == gridSize - 1 || c == 0 || c == gridColSize[r] - 1) {
            isBorder = 1;
        } else {
            // Check if it's adjacent to a different color
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                
                // If adjacent cell is out of bounds or has a different color
                if (nr < 0 || nr >= gridSize || nc < 0 || nc >= gridColSize[nr] || 
                    grid[nr][nc] != originalColor) {
                    isBorder = 1;
                    break;
                }
            }
        }
        
        // If it's a border cell, color it
        if (isBorder) {
            result[r][c] = color;
        }
        
        // Continue DFS for adjacent cells of the same color
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            
            // Check if the adjacent cell is valid and has the same color
            if (nr >= 0 && nr < gridSize && nc >= 0 && nc < gridColSize[nr] && 
                !visited[nr][nc] && grid[nr][nc] == originalColor) {
                dfs(nr, nc);
            }
        }
    }
    
    // Start DFS from the given cell
    dfs(row, col);
    
    // Free the visited array
    for (int i = 0; i < gridSize; i++) {
        free(visited[i]);
    }
    free(visited);
    
    return result;
}
