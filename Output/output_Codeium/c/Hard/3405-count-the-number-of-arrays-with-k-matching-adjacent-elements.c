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
    int MOD = 1e9 + 7;
    long long dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] += dp[i - 1][j] * (m - 1) % MOD;
            if (j > 0) dp[i][j] += dp[i - 1][j - 1] % MOD;
            dp[i][j] %= MOD;
        }
    }
    return dp[n][k];
}