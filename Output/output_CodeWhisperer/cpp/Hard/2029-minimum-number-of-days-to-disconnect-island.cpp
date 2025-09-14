/**https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/ */
//You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
//The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
//In one day, we are allowed to change any single land cell (1) into a water cell (0).
//Return the minimum number of days to disconnect the grid.
// 
//Example 1:
//Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
//Output: 2
//Explanation: We need at least 2 days to get a disconnected grid.
//Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
//Example 2:
//Input: grid = [[1,1]]
//Output: 2
//Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 30
//	grid[i][j] is either 0 or 1.    
class Solution {
    public:
        int minDays(vector<vector<int>>& grid) {
            // Check if the grid is already disconnected
            if (isDisconnected(grid)) {
                return 0;
            }
            
            // Try removing each land cell to see if it disconnects the grid
            int m = grid.size();
            int n = grid[0].size();
            
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        // Temporarily remove this land cell
                        grid[i][j] = 0;
                        
                        // Check if the grid becomes disconnected
                        if (isDisconnected(grid)) {
                            // Restore the grid
                            grid[i][j] = 1;
                            return 1;
                        }
                        
                        // Restore the grid
                        grid[i][j] = 1;
                    }
                }
            }
            
            // If we can't disconnect with 1 cell, we can always do it with 2
            return 2;
        }
        
    private:
        // Directions: up, right, down, left
        const int dx[4] = {-1, 0, 1, 0};
        const int dy[4] = {0, 1, 0, -1};
        
        // Check if the grid is disconnected (0 or >1 islands)
        bool isDisconnected(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            
            // Find the first land cell
            int firstLandX = -1, firstLandY = -1;
            for (int i = 0; i < m && firstLandX == -1; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        firstLandX = i;
                        firstLandY = j;
                        break;
                    }
                }
            }
            
            // If no land cell, the grid is disconnected
            if (firstLandX == -1) {
                return true;
            }
            
            // Count land cells and perform DFS from the first land cell
            int totalLandCells = 0;
            int visitedLandCells = 0;
            
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        totalLandCells++;
                    }
                }
            }
            
            dfs(grid, visited, firstLandX, firstLandY, visitedLandCells);
            
            // If not all land cells were visited, the grid is disconnected
            return visitedLandCells != totalLandCells;
        }
        
        // DFS to count connected land cells
        void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& count) {
            int m = grid.size();
            int n = grid[0].size();
            
            // Mark current cell as visited and increment count
            visited[x][y] = true;
            count++;
            
            // Explore all four directions
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // Check if the new position is valid
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    grid[nx][ny] == 1 && !visited[nx][ny]) {
                    dfs(grid, visited, nx, ny, count);
                }
            }
        }
    };
    