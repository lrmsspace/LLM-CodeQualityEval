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
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int mod = 1000000007;
        int dp[50][50][51] = {0};
        for (int k = 1; k <= maxMove; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    long long val = 0;
                    val += i == 0 ? 1 : dp[i - 1][j][k - 1];
                    val += i == m - 1 ? 1 : dp[i + 1][j][k - 1];
                    val += j == 0 ? 1 : dp[i][j - 1][k - 1];
                    val += j == n - 1 ? 1 : dp[i][j + 1][k - 1];
                    dp[i][j][k] = val % mod;
                }
            }
        }
        return dp[startRow][startColumn][maxMove];     
    }
};