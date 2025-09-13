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
        int MOD = 1000000007;
        int[][] dp = new int[m][n];
        dp[startRow][startColumn] = 1;
        
        for (int move = 1; move <= maxMove; move++) {
            int[][] next = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (int[] dir : directions) {
                        int x = i + dir[0], y = j + dir[1];
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            next[x][y] = (next[x][y] + dp[i][j]) % MOD;
                        }
                    }
                }
            }
            dp = next;
        }
        
        int count = 0;
        for (int[] row : dp) {
            for (int cell : row) {
                count = (count + cell) % MOD;
            }
        }
        
        return count;
        
    }
}