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
    const int MOD = 1e9 + 7;
    const int N = 6;
    int dp[N][1 << N];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int mask = 0; mask < (1 << N); ++mask) {
            if (dp[i][mask]) {
                for (int j = 0; j < N; ++j) {
                    int next_mask = mask ^ (1 << j);
                    if (!(next_mask & (1 << (j - 1))) && !(next_mask & (1 << (j + 1)))) {
                        dp[i + 1][next_mask] = (dp[i + 1][next_mask] + dp[i][mask]) % MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << N); ++i) ans = (ans + dp[m][i]) % MOD;
    return ans;
}