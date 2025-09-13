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
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int MOD = 1_000_000_007;
        int[][] dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        int[][] dp = new int[m][n];
        dp[startRow][startColumn] = 1;
        int res = 0;
        for (int k = 0; k < maxMove; k++) {
            int[][] dp2 = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][j] > 0) {
                        for (int[] d : dirs) {
                            int ni = i + d[0], nj = j + d[1];
                            if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                                res = (res + dp[i][j]) % MOD;
                            else
                                dp2[ni][nj] = (dp2[ni][nj] + dp[i][j]) % MOD;
                        }
                    }
                }
            }
            dp = dp2;
        }
        return res;
    }
}