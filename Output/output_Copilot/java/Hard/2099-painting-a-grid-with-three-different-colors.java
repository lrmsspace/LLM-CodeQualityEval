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
          int mod = 1000000007;
            long[][] dp = new long[m + 1][1 << (2 * m)];
            dp[0][0] = 1; // Base case: no rows, one way to color (empty grid)
            
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < (1 << (2 * m)); j++) {
                    if (dp[i - 1][j] == 0) continue; // Skip if no ways to color the previous row
                    for (int k = 0; k < (1 << (2 * m)); k++) {
                        if (isValid(j, k, m)) {
                            dp[i][k] = (dp[i][k] + dp[i - 1][j]) % mod;
                        }
                    }
                }
            }
            
            long result = 0;
            for (int j = 0; j < (1 << (2 * m)); j++) {
                result = (result + dp[n][j]) % mod;
            }
            
            return (int) result;      
    }
}