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
int colorTheGrid(int m, int n) {
    int mod = 1000000007;
    int dp[m][n][1 << m];
    memset(dp, 0, sizeof(dp));
    for (int mask = 0; mask < (1 << m); mask++) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                cnt++;
            }
        }
        if (cnt == 1) {
            dp[0][0][mask] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int mask1 = 0; mask1 < (1 << m); mask1++) {
            for (int mask2 = 0; mask2 < (1 << m); mask2++) {
                int valid = 1;
                for (int j = 0; j < m; j++) {
                    if (mask1 & (1 << j)) {
                        if (j > 0 && (mask2 & (1 << (j - 1)))) {
                            valid = 0;
                            break;
                        }
                        if (j < m - 1 && (mask2 & (1 << (j + 1)))) {
                            valid = 0;
                            break;
                        }
                    }
                }
                if (valid) {
                    for (int mask3 = 0; mask3 < (1 << m); mask3++) {
                        if ((mask1 & mask2) == 0 && (mask2 & mask3) == 0 && (mask1 & mask3) == 0) {
                            dp[i][mask2][mask1] = (dp[i][mask2][mask1] + dp[i - 1][mask3][mask2]) % mod;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        ans = (ans + dp[n - 1][mask][0]) % mod;
    }
    return ans;    
}