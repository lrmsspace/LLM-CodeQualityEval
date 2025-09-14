/**https://leetcode.com/problems/as-far-from-land-as-possible/ */
//Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.
//The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
// 
//Example 1:
//Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
//Output: 2
//Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
//Example 2:
//Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
//Output: 4
//Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 100
//	grid[i][j] is 0 or 1
int maxDistance(int** grid, int gridSize, int* gridColSize) {
    int i, j, k, l, n = gridSize, m = gridColSize[0], max = 0, flag = 0;
    int** dp = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++) {
        dp[i] = (int*)malloc(sizeof(int) * m);
        for (j = 0; j < m; j++) {
            dp[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = n + m;
                if (i > 0) {
                    dp[i][j] = dp[i][j] < dp[i - 1][j] + 1 ? dp[i][j] : dp[i - 1][j] + 1;
                }
                if (j > 0) {
                    dp[i][j] = dp[i][j] < dp[i][j - 1] + 1 ? dp[i][j] : dp[i][j - 1] + 1;
                }
            }
        }
    }
    for (i = n - 1; i >= 0; i--) {
        for (j = m - 1; j >= 0; j--) {
            if (grid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                if (i < n - 1) {
                    dp[i][j] = dp[i][j] < dp[i + 1][j] + 1 ? dp[i][j] : dp[i + 1][j] + 1;
                }
                if (j < m - 1) {
                    dp[i][j] = dp[i][j] < dp[i][j + 1] + 1 ? dp[i][j] : dp[i][j + 1] + 1;
                }
            }
            if (dp[i][j] > max) {
                max = dp[i][j];
            }
        }
    }
    for (i = 0;    i < n; i++) {
        for (j = 0; j < m; j++) {
            if (dp[i][j] == n + m) {
                flag = 1;
                break;
            }
        }
    }
    for (i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    return flag == 1 ? -1 : max;
}