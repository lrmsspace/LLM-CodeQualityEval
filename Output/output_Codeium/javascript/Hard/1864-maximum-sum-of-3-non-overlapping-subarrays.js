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
const n = nums.length;
const sum = Array(n + 1).fill(0);   

// Compute cumulative sum
for (let i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + nums[i];
}

// Arrays to store the best indices for the first and second subarrays
const left = Array(n).fill(0);
const right = Array(n).fill(n - k);

let maxSum = 0;
for (let i = k - 1; i < n; i++) {
    const currSum = sum[i + 1] - sum[i + 1 - k];
    if (currSum > maxSum) {
        maxSum = currSum;
        left[i] = i + 1 - k;
    } else {
        left[i] = left[i - 1];
    }
}

maxSum = 0;
for (let i = n - k; i >= 0; i--) {
    const currSum = sum[i + k] - sum[i];
    if (currSum >= maxSum) {
        maxSum = currSum;
        right[i] = i;
    } else {
        right[i] = right[i + 1];
    }
}

let result = [-1, -1, -1];
maxSum = 0;

// Find the three non-overlapping subarrays with maximum sum
for (let i = k; i <= n - 2 * k; i++) {
    const l = left[i - 1];
    const r = right[i + k];
    const totalSum = (sum[i + k] - sum[i]) + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r]);

    if (totalSum > maxSum) {
        maxSum = totalSum;
        result = [l, i, r];
    }
}

return result;

};