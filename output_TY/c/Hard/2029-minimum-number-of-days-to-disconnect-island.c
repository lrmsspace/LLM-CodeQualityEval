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
int minDays(int** grid, int gridSize, int* gridColSize){
    int m = gridSize, n = *gridColSize;
    int i, j, k, l, cnt = 0, ans = 0, flag = 0;
    int* row = (int*)malloc(m * sizeof(int));
    int* col = (int*)malloc(n * sizeof(int));
    memset(row, 0, m * sizeof(int));
    memset(col, 0, n * sizeof(int));
    for (i = 0; i <m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                row[i]++;
                col[j]++;
            }
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                for (k = 0; k < m; k++) {
                    if (row[k] == 1) {
                        flag = 1;
                        break;
                   }
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (grid[j][i] == 1) {
                grid[j][i] = 0;
                for (k = 0; k < n; k++) {
                    if (col[k] == 1) {
                        flag = 1;
                        break;
                   }
                }
            }
        }
    }
    if (flag == 1) {
        return 1;
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                cnt++;
            }
        }
    }
    if (cnt == 0) {
        return 0;
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                for (k = 0; k < m; k++) {
                    for (l = 0; l < n; l++) {
                        if (grid[k][l] ==1) {
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
    }
    return ans;
}