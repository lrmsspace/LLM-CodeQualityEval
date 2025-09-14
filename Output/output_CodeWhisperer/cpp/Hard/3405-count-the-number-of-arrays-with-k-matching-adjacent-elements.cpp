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

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int x = 1; x <= m; x++) {
                    if (i - x >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - x][j - 1]) % mod;
                        if (j == k) {
                            dp[i][j] = (dp[i][j] + dp[i - x][j]) % mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = (ans + dp[i][k]) % mod;
        }
        return ans;

    }
};