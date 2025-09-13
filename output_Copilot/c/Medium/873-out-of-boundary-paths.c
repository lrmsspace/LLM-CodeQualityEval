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
    int mod = 1000000007;
    int dp[m][n][maxMove + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j][0] = (i == 0) + (i == m - 1) + (j == 0) + (j == n - 1);
        }
    }
    int res = dp[startRow][startColumn][0];
    for (int k = 1; k <= maxMove; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][k] = ((i == 0 ? 1 : dp[i - 1][j][k - 1]) + (i == m - 1 ? 1 : dp[i + 1][j][k - 1]) + (j == 0 ? 1 : dp[i][j - 1][k - 1]) + (j == n - 1 ? 1 : dp[i][j + 1][k - 1])) % mod;
            }
        }
        res = (res + dp[startRow][startColumn][k]) % mod;
    }
    return res;    
}