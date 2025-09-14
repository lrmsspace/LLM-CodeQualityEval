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
    let sum = 0;
    let dp = new Array(n - k + 1).fill(0);
    for (let i = 0; i < k; i++) {
        sum += nums[i];
    }
    dp[0] = sum;
    for (let i = k; i < n; i++) {
        sum = sum - nums[i - k] + nums[i];
        dp[i - k + 1] = sum;
    }
    let left = new Array(n).fill(0);
    let max = 0;
    for (let i = 0; i < n; i++) {
        if (dp[i] > dp[max]) {
            max = i;
        }
        left[i] = max;
    }
    let right = new Array(n).fill(n - k);
    max = n - k;
    for (let i = n - k; i >= 0; i--) {
        if (dp[i] >= dp[max]) {
            max = i;
        }
        right[i] = max;
    }
    let res = new Array(3).fill(0);
    for (let i = k; i <= n - 2 * k; i++) {
        let l = left[i - k];
        let r = right[i + k];
        if (dp[l] + dp[i] + dp[r] > dp[res[0]] + dp[res[1]] + dp[res[2]]) {
            res[0] = l;
            res[1] = i;
            res[2] = r;
        }
    }
    return res;
};