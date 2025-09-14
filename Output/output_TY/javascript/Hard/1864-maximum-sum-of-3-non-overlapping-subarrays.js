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
    let left = new Array(n).fill(0);
    let right = new Array(n).fill(0);
    let leftSum = 0;
    for (let i = k; i < n; i++) {
        leftSum += nums[i - k];
        left[i] = leftSum;
    }
    let rightSum = 0;
    for (let i = n - k - 1; i >= 0; i--) {
        rightSum += nums[i + k];
        right[i] = rightSum;
    }
    let maxSum = 0;
    let ans = [];
    for (let i = k; i <= n - 2 * k; i++) {
        let sum = left[i - k] + right[i] + nums.slice(i, i + k).reduce((a, b) => a + b);
        if (sum > maxSum) {
            maxSum = sum;
            ans = [i - k, i, i + k];
        }
    }
    return ans;
};