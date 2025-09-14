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
int minDays(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = *gridColSize;
    int dirs[5] = {0, 1, 0, -1, 0};
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            count += grid[i][j];
        }
    }
    if (count == 0 || count == m * n) {
        return 0;
    }
    if (count == 1) {
        return 1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                int island = 0;
                for (int k = 0; k < 4; k++) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        island++;
                    }
                }
                if (island == 0) {
                    return 1;
                }
                grid[i][j] = 1;
            }
        }
    }
    return 2;   
}