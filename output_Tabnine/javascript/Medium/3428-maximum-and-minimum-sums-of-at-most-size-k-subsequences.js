/*
 You are given an integer array nums and a positive integer k. Return the sum of the maximum and minimum elements of all subsequences of nums with at most k elements.
 Since the answer may be very large, return it modulo 109 + 7.
 Example 1:
 Input: nums = [1,2,3], k = 2
 Output: 24
 Explanation:
 The subsequences of nums with at most 2 elements are:
 Subsequence 
 Minimum
 Maximum
 Sum
 [1]
 1
 1
 2
 [2]
 2
 2
 4
 [3]
 3
 3
 6
 [1, 2]
 1
 2
 3
 [1, 3]
 1
 3
 4
 [2, 3]
 2
 3
 5
 Final Total
 24
 The output would be 24.
 Example 2:
 Input: nums = [5,0,6], k = 1
 Output: 22
 Explanation: 
 For subsequences with exactly 1 element, the minimum and maximum values are the element itself. Therefore, the total is 5 + 5 + 0 + 0 + 6 + 6 = 22.
 Example 3:
 Input: nums = [1,1,1], k = 2
 Output: 12
 Explanation:
 The subsequences [1, 1] and [1] each appear 3 times. For all of them, the minimum and maximum are both 1. Thus, the total is 12.
 Constraints:
 1 <= nums.length <= 105
 0 <= nums[i] <= 109
 1 <= k <= min(70, nums.length)
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minMaxSums = function(nums, k) {
    const MOD = 10 ** 9 + 7;
    const n = nums.length;
    const dp = Array(n + 1).fill(0).map(() => Array(k + 1).fill(0));
    
    // Base cases
    for (let i = 0; i <= n; i++) {
        dp[i][0] = 0;
        dp[i][i] = nums[i];
    }
    
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= k && j <= i; j++) {
            dp[i][j] = Math.max(dp[i - 1][j - 1], nums[i - 1]) + dp[i - 1][j];
        }
    }
    
    let minSum = Infinity;
    let maxSum = 0; 
    for (let i = 1; i <= n; i++) {
        minSum = Math.min(minSum, dp[n][k] - dp[i - 1][k - 1]);
        maxSum = Math.max(maxSum, dp[i - 1][k - 1]);
    }
    return (minSum + maxSum) % MOD;
    
};