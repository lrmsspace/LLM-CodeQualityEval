/*
 You are given three integers n, m, k. A good array arr of size n is defined as follows:
 Each element in arr is in the inclusive range [1, m].
 Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].
 Return the number of good arrays that can be formed.
 Since the answer may be very large, return it modulo 109 + 7.
 Example 1:
 Input: n = 3, m = 2, k = 1
 Output: 4
 Explanation:
 There are 4 good arrays. They are [1, 1, 2], [1, 2, 2], [2, 1, 1] and [2, 2, 1].
 Hence, the answer is 4.
 Example 2:
 Input: n = 4, m = 2, k = 2
 Output: 6
 Explanation:
 The good arrays are [1, 1, 1, 2], [1, 1, 2, 2], [1, 2, 2, 2], [2, 1, 1, 1], [2, 2, 1, 1] and [2, 2, 2, 1].
 Hence, the answer is 6.
 Example 3:
 Input: n = 5, m = 2, k = 0
 Output: 2
 Explanation:
 The good arrays are [1, 2, 1, 2, 1] and [2, 1, 2, 1, 2]. Hence, the answer is 2.
 Constraints:
 1 <= n <= 105
 1 <= m <= 105
 0 <= k <= n - 1
*/

int countGoodArrays(int n, int m, int k) {
    int mod = 1000000007;
    int dp[n + 1][k + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        dp[1][0][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int total = 0;
            for (int x = 1; x <= m; x++) {
                dp[i][j][x] = (dp[i][j][x] + total) % mod;
                for (int y = 1; y < x; y++) {
                    dp[i][j][x] = (dp[i][j][x] + dp[i - 1][j - 1][y]) % mod;
                }
                total = (total + dp[i - 1][j][x]) % mod;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= m; i++) {
        res = (res + dp[n][k][i]) % mod;
    }
    return res;    
}