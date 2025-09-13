/**https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/ */
//Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
//Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
// 
//Example 1:
//Input: nums = [1,2,1,2,6,7,5,1], k = 2
//Output: [0,3,5]
//Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
//We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
//Example 2:
//Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
//Output: [0,2,4]
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i] < 216
//	1 <= k <= floor(nums.length / 3)
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSumOfThreeSubarrays = function(nums, k) {
    let n = nums.length;
    let dp = Array.from({ length: n + 1 }, () => Array(4).fill(0));
    let sum = Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + nums[i];
    }
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= 3; j++) {
            if (i >= k) {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i - k][j - 1] + sum[i] - sum[i - k]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let res = [];
    let maxSum = 0;
    for (let i = n; i >= k; i--) {
        if (dp[i][3] > maxSum) {
            maxSum = dp[i][3];
            res[2] = i - k;
        }
        if (i >= k) {
            res[1] = Math.max(res[1], dp[i - k][2]);
        }
        if (i >= k * 2) {
            res[0] = Math.max(res[0], dp[i - k * 2][1]);
        }
    }
    return res;    
};