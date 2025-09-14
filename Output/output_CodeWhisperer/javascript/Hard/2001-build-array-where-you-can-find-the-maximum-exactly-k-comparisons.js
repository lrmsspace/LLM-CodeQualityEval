/**https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/ */
//You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:
//You should build the array arr which has the following properties:
//	arr has exactly n integers.
//	1 <= arr[i] <= m where (0 <= i < n).
//	After applying the mentioned algorithm to arr, the value search_cost is equal to k.
//Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 109 + 7.
// 
//Example 1:
//Input: n = 2, m = 3, k = 1
//Output: 6
//Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
//Example 2:
//Input: n = 5, m = 2, k = 3
//Output: 0
//Explanation: There are no possible arrays that satisfy the mentioned conditions.
//Example 3:
//Input: n = 9, m = 1, k = 1
//Output: 1
//Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]
// 
//Constraints:
//	1 <= n <= 50
//	1 <= m <= 100
//	0 <= k <= n
/**
 * @param {number} n
 * @param {number} m
 * @param {number} k
 * @return {number}
 */
var numOfArrays = function(n, m, k) {
    const MOD = 1000000007;
    const dp = new Array(n + 1).fill(0).map(() => new Array(k + 1).fill(0).map(() => new Array(m + 1).fill(0)));
    for (let j = 1; j <= m; j++) {
        dp[1][1][j] = 1;
    }
    for (let i = 2; i <= n; i++) {
        for (let j = 1; j <= k; j++) {
            for (let x = 1; x <= m; x++) {
                for (let y = 1; y <= m; y++) {
                    if (y <= x) {
                        dp[i][j][x] = (dp[i][j][x] + dp[i - 1][j - 1][y]) % MOD;
                    }
                    dp[i][j][x] = (dp[i][j][x] + (x * dp[i - 1][j][x]) % MOD) % MOD;
                }
            }
        }
    }
    let res = 0;
    for (let j = 1; j <= m; j++) {
        res = (res + dp[n][k][j]) % MOD;
    }
    return res;
};