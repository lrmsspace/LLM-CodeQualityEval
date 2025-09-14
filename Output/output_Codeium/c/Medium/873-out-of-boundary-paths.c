/**https://leetcode.com/problems/out-of-boundary-paths/ */
//There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
//Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
//Output: 6
//Example 2:
//Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
//Output: 12
// 
//Constraints:
//	1 <= m, n <= 50
//	0 <= maxMove <= 50
//	0 <= startRow < m
//	0 <= startColumn < n
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    const int MOD = 1e9 + 7;
    int dp[maxMove + 1][m][n] = {0};
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int k = 1; k <= maxMove; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    dp[k][i][j] = 1;
                } else {
                    for (int d = 0; d < 4; d++) {
                        int x = i + dx[d], y = j + dy[d];
                        dp[k][i][j] = (dp[k][i][j] + dp[k - 1][x][y]) % MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int d = 0; d < 4; d++) {
        int x = startRow + dx[d], y = startColumn + dy[d];
        if (x < 0 || x >= m || y < 0 || y >= n)
            ans = (ans + 1) % MOD;
        else
            ans = (ans + dp[maxMove][x][y]) % MOD;
    }
    return ans;
    
}