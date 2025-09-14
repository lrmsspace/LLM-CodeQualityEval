/**https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/ */
//You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:
//	0 represents an empty cell,
//	1 represents an obstacle that may be removed.
//You can move up, down, left, or right from and to an empty cell.
//Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).
// 
//Example 1:
//Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
//Output: 2
//Explanation: We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
//It can be shown that we need to remove at least 2 obstacles, so we return 2.
//Note that there may be other ways to remove 2 obstacles to create a path.
//Example 2:
//Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
//Output: 0
//Explanation: We can move from (0, 0) to (2, 4) without removing any obstacles, so we return 0.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 105
//	2 <= m * n <= 105
//	grid[i][j] is either 0 or 1.
//	grid[0][0] == grid[m - 1][n - 1] == 0
int minimumObstacles(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int dp[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    dp[0][0] = 0;
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (int k = 0; k < m * n; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int d = 0; d < 4; d++) {
                    int x = i + dirs[d][0], y = j + dirs[d][1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (grid[i][j] == 0) {
                            dp[x][y] = fmin(dp[x][y], dp[i][j]);
                        } else {
                            dp[x][y] = fmin(dp[x][y], dp[i][j] + 1);
                        }
                    }
                }
            }
        }
    }
    return dp[m - 1][n - 1];
}