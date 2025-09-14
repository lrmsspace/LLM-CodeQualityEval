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

bool isConnected(int** grid, int gridSize, int* gridColSize) {
    int visited[gridSize][*gridColSize];
    memset(visited, 0, sizeof(visited));
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                dfs(grid, gridSize, gridColSize, i, j, visited, &count);
                count++;
            }
        }
    }
    return count == 1;
}

void dfs(int** grid, int gridSize, int* gridColSize, int i, int j, int** visited, int* count) {
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize[i] || grid[i][j] == 0 || visited[i][j]) return;
    visited[i][j] = 1;
    (*count)++;
    dfs(grid, gridSize, gridColSize, i - 1, j, visited, count);
    dfs(grid, gridSize, gridColSize, i + 1, j, visited, count);
    dfs(grid, gridSize, gridColSize, i, j - 1, visited, count);
    dfs(grid, gridSize, gridColSize, i, j + 1, visited, count);
}

int minDays(int** grid, int gridSize, int* gridColSize) {
    int res = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                if (isConnected(grid, gridSize, gridColSize)) {
                    res++;
                }
                grid[i][j] = 1;
            }
        }
    }
    return res;
}   