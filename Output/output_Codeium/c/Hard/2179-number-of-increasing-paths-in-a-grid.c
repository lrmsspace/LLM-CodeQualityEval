/**https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/ */
//You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.
//Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.
//Two paths are considered different if they do not have exactly the same sequence of visited cells.
// 
//Example 1:
//Input: grid = [[1,1],[3,4]]
//Output: 8
//Explanation: The strictly increasing paths are:
//- Paths with length 1: [1], [1], [3], [4].
//- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
//- Paths with length 3: [1 -> 3 -> 4].
//The total number of paths is 4 + 3 + 1 = 8.
//Example 2:
//Input: grid = [[1],[2]]
//Output: 3
//Explanation: The strictly increasing paths are:
//- Paths with length 1: [1], [2].
//- Paths with length 2: [1 -> 2].
//The total number of paths is 2 + 1 = 3.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 1000
//	1 <= m * n <= 105
//	1 <= grid[i][j] <= 105
int countPaths(int** grid, int gridSize, int* gridColSize) {
    int MOD = 1e9 + 7;
    int m = gridSize;
    int n = gridColSize[0];
    int dp[m][n];
    memset(dp, 0, sizeof(dp));

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] < grid[i][j]) {
                    dp[i][j] = (dp[i][j] + dp[x][y]) % MOD;
                }
            }
            if (dp[i][j] == 0) {
                dp[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = (ans + dp[i][j]) % MOD;
        }
    }
    return ans;
}