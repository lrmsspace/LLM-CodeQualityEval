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
int findPaths(int m, int n, int maxMove, int startRow, int startColumn){
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    dp[startRow][startColumn] = 1;
    int ans = 0;
    for (int i = 0; i < maxMove; i++) {
        int dp2[m][n];
        memset(dp2, 0, sizeof(dp2));
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (j == 0) ans += dp[j][k];
                if (j == m - 1) ans += dp[j][k];
                if (k == 0) ans += dp[j][k];
                if (k == n - 1) ans += dp[j][k];
                dp2[j][k] += dp[j][k];
            }
        }
    }
    return ans % MOD;
}