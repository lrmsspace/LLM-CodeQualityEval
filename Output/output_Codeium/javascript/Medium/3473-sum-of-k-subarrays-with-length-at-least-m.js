/*
 You are given an integer array nums and two integers, k and m.
 Return the maximum sum of k non-overlapping subarrays of nums, where each subarray has a length of at least m.
 Example 1:
 Input: nums = [1,2,-1,3,3,4], k = 2, m = 2
 Output: 13
 Explanation:
 The optimal choice is:
 Subarray nums[3..5] with sum 3 + 3 + 4 = 10 (length is 3 >= m).
 Subarray nums[0..1] with sum 1 + 2 = 3 (length is 2 >= m).
 The total sum is 10 + 3 = 13.
 Example 2:
 Input: nums = [-10,3,-1,-2], k = 4, m = 1
 Output: -10
 Explanation:
 The optimal choice is choosing each element as a subarray. The output is (-10) + 3 + (-1) + (-2) = -10.
 Constraints:
 1 <= nums.length <= 2000
 -104 <= nums[i] <= 104
 1 <= k <= floor(nums.length / m)
 1 <= m <= 3
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} m
 * @return {number}
 */
var maxSum = function(nums, k, m) {
    let dp = new Array(nums.length).fill(0).map(x => new Array(k+1).fill(0));
    let sum = 0;
    for (let i = 0; i < nums.length; i++) {
        sum += nums[i];
        dp[i][0] = sum;
        if (i >= m-1) dp[i][1] = Math.max(dp[i-1][1], dp[i-m+1][0]);
        for (let j = 2; j <= k && i >= j*m-1; j++) {
            dp[i][j] = Math.max(dp[i-1][j], dp[i-m+1][j-1] + dp[i][0] - dp[i-m+1][0]);
        }
    }
    return dp[nums.length-1][k];
};