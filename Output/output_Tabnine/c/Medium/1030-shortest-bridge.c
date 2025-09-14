/**https://leetcode.com/problems/shortest-bridge/ */
//You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
//An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
//You may change 0's to 1's to connect the two islands to form one island.
//Return the smallest number of 0's you must flip to connect the two islands.
// 
//Example 1:
//Input: grid = [[0,1],[1,0]]
//Output: 1
//Example 2:
//Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
//Output: 2
//Example 3:
//Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
//Output: 1
// 
//Constraints:
//	n == grid.length == grid[i].length
//	2 <= n <= 100
//	grid[i][j] is either 0 or 1.
//	There are exactly two islands in grid.
int shortestBridge(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int minSteps = INT_MAX;
    int rows[n * n];
    int cols[n * n];
    int numIslands = 0;
    int islandSize = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                rows[numIslands] = i;
                cols[numIslands] = j;
                numIslands++;
            }
        }
    }
    
    int* visited = (int*)calloc(n * n, sizeof(int));
    
    for (int i = 0; i < numIslands; i++) {
        memset(visited, 0, n * n * sizeof(int));
        int startRow = rows[i];
        int startCol = cols[i];
        int steps = 0;
        
        while (true) {
            int newRows[4] = {startRow - 1, startRow + 1, startRow, startRow};
            int newCols[4] = {startCol, startCol, startCol - 1, startCol + 1};
            
            for (int j = 0; j < 4; j++) {
                int newRow = newRows[j];
                int newCol = newCols[j];
                
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1 &&!visited[newRow * n + newCol]) {
                    visited[newRow * n + newCol] = 1;
                    startRow = newRow;
                    startCol = newCol;
                    steps++;
                    break;
                }
            }
            
            if (steps > 0) {
                break;
            }
        }
        
        if (steps < minSteps) {
            minSteps = steps;
        }
        
        for (int j = 0; j < n * n; j++) {
            if (visited[j]) {
                grid[rows[j / n]][cols[j / n]] = 0;
                islandSize++;
            }
        }
        
        free(visited);
        visited = (int*)calloc(n * n, sizeof(int));

    }
    
    return minSteps;
    
}