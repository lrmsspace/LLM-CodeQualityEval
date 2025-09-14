/**https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/ */
//You are given a 0-indexed m x n integer matrix grid. Your initial position is at the top-left cell (0, 0).
//Starting from the cell (i, j), you can move to one of the following cells:
//	Cells (i, k) with j < k <= grid[i][j] + j (rightward movement), or
//	Cells (k, j) with i < k <= grid[i][j] + i (downward movement).
//Return the minimum number of cells you need to visit to reach the bottom-right cell (m - 1, n - 1). If there is no valid path, return -1.
// 
//Example 1:
//Input: grid = [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]
//Output: 4
//Explanation: The image above shows one of the paths that visits exactly 4 cells.
//Example 2:
//Input: grid = [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]
//Output: 3
//Explanation: The image above shows one of the paths that visits exactly 3 cells.
//Example 3:
//Input: grid = [[2,1,0],[1,0,0]]
//Output: -1
//Explanation: It can be proven that no path exists.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	0 <= grid[i][j] < m * n
//	grid[m - 1][n - 1] == 0
int minimumVisitedCells(int** grid, int gridSize, int* gridColSize)
{
    int m = gridSize;
    int n = gridColSize[0];
    int** dp = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int min = INT_MAX;
            for (int k = 0; k < i; k++) {
                if (grid[k][j] + k >= i) {
                    min = fmin(min, dp[k][j]);
                }
            }
            for (int k = 0; k < j; k++) {
                if (grid[i][k] + k >= j) {
                    min = fmin(min, dp[i][k]);
                }
            }
            if (min != INT_MAX) {
                dp[i][j] = min + 1;
            }
        }
    }
    return dp[m - 1][n - 1] == -1 ? -1 : dp[m - 1][n - 1];
}