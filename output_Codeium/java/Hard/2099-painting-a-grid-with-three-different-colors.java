/**https://leetcode.com/problems/painting-a-grid-with-three-different-colors/ */
//You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.
//Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: m = 1, n = 1
//Output: 3
//Explanation: The three possible colorings are shown in the image above.
//Example 2:
//Input: m = 1, n = 2
//Output: 6
//Explanation: The six possible colorings are shown in the image above.
//Example 3:
//Input: m = 5, n = 5
//Output: 580986
// 
//Constraints:
//	1 <= m <= 5
//	1 <= n <= 1000
class Solution {
    public int colorTheGrid(int m, int n) {
        final int MOD = 1_000_000_007;
        int[][] dp = new int[m][1 << n];
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < (1 << n); j++) {
                if (dp[i][j] == 0) continue;
                for (int k = 0; k < (1 << n); k++) {
                    if (((j >> 1) & k) != 0 || ((j & k) << 1) != 0) continue;
                    dp[(i + 1) % m][k] = (dp[(i + 1) % m][k] + dp[i][j]) % MOD;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < (1 << n); i++) {
            sum = (sum + dp[m - 1][i]) % MOD;
        }
        return sum;
    }
}