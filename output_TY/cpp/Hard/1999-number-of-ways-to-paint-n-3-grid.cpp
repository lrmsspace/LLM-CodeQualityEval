/**https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/ */
//You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).
//Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.
// 
//Example 1:
//Input: n = 1
//Output: 12
//Explanation: There are 12 possible way to paint the grid as shown.
//Example 2:
//Input: n = 5000
//Output: 30228214
// 
//Constraints:
//	n == grid.length
//	1 <= n <= 5000
class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9 + 7;
        long long dp[n + 1][3][3];
        memset(dp, 0, sizeof(dp));
        dp[1][0][0] = dp[1][1][1] = dp[1][2][2] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j != k) {
                        dp[i][j][k] = dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2];
                    }
                    else {
                        dp[i][j][k] = dp[i - 1][j][0] * 2 + dp[i - 1][j][1] * 1 + dp[i - 1][j][2] * 2;
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ans = (ans + dp[n][i][j]) % mod;
            }
        }
        return ans;
    }
};