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

/**
 * @param {number} n
 * @param {number} m
 * @param {number} k
 * @return {number}
 */
var countGoodArrays = function(n, m, k) {
    // Base cases
    if (n <= 2) return n;
    if (k === 0) return 1;
    
    // Initialize variables
    let MOD = 10 ** 9 + 7;
    let dp = Array(n + 1).fill(0);
    dp[0] = dp[1] = 1;
    
    // Calculate dp[i] using modulo
    for (let i = 2; i <= n; i++) {
        for (let j = 1; j * j <= i; j++) {
            if (i % j === 0) {
                dp[i] = (dp[i] + dp[i / j]) % MOD;
                if (j * j!== i) dp[i] = (dp[i] + dp[i / (j * j)]) % MOD;
            }
        }
    }
    
    // Calculate the number of good arrays
    let goodArrays = 0;
    for (let i = 1; i <= n; i++) {
        if (dp[i] === 1 && i - k >= 0 && dp[i - k] === 1) {
            goodArrays = (goodArrays + dp[i]) % MOD;
        }
    }
    
    return goodArrays;
    
};