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
public:
    int colorTheGrid(int m, int n) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(3, 0));
        vector<vector<int>> next(3, vector<int>(3, 0));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    next[i][j] = 1;
                }
            }
        }
        dp[0][0] = dp[0][1] = dp[0][2] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j< m; j++) {
                dp[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (k != l) {
                            dp[i][j] += dp[i - 1][l] * next[k][l];
                        }
                    }
                }
                dp[i][j] %= mod;
                next[j] = dp[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            ans += dp[n - 1][i];
        }
        return ans % mod;
    }
};