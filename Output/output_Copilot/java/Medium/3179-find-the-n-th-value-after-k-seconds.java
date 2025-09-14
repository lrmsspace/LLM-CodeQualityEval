/*
 You are given two integers n and k.
 Initially, you start with an array a of n integers where a[i] = 1 for all 0 <= i <= n - 1. After each second, you simultaneously update each element to be the sum of all its preceding elements plus the element itself. For example, after one second, a[0] remains the same, a[1] becomes a[0] + a[1], a[2] becomes a[0] + a[1] + a[2], and so on.
 Return the value of a[n - 1] after k seconds.
 Since the answer may be very large, return it modulo 109 + 7.
 Example 1:
 Input: n = 4, k = 5
 Output: 56
 Explanation:
 Second
 State After
 0
 [1,1,1,1]
 1
 [1,2,3,4]
 2
 [1,3,6,10]
 3
 [1,4,10,20]
 4
 [1,5,15,35]
 5
 [1,6,21,56]
 Example 2:
 Input: n = 5, k = 3
 Output: 35
 Explanation:
 Second
 State After
 0
 [1,1,1,1,1]
 1
 [1,2,3,4,5]
 2
 [1,3,6,10,15]
 3
 [1,4,10,20,35]
 Constraints:
 1 <= n, k <= 1000
*/

class Solution {
    public int valueAfterKSeconds(int n, int k) {
        long mod = 1000000007;
        long[][] dp = new long[k + 1][n + 1];

        // Base case: After 0 seconds, all elements are 1
        for (int i = 1; i <= n; i++) {
            dp[0][i] = 1;
        }

        // Fill the dp table
        for (int sec = 1; sec <= k; sec++) {
            for (int i = 1; i <= n; i++) {
                dp[sec][i] = (dp[sec - 1][i] + dp[sec][i - 1]) % mod;
            }
        }

        return (int) dp[k][n];
    }
}