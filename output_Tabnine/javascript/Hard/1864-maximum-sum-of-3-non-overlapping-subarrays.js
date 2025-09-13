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
    const prefixSum = Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }
    
    const dp = Array(n).fill(0).map(() => Array(n).fill(0).map(() => Array(k).fill(-Infinity)));
    for (let i = 0; i < n - k + 1; i++) {
        dp[i][i][0] = prefixSum[i + k] - prefixSum[i];
    }
    
    for (let len = 2; len <= k; len++) {
        for (let i = 0; i < n - len + 1; i++) {
            const j = i + len - 1;
            for (let mid = i; mid < j; mid++) {
                dp[i][j][len - 1] = Math.max(dp[i][j][len - 1], prefixSum[j + 1] - prefixSum[i] - dp[i][mid][len - 2]);
            }
        }
    }
    
    let maxSum = -Infinity;
    let result = [];
    for (let i = 0; i < n - k * 2 + 1; i++) {
        for (let j = i + k - 1; j < n - k + 1; j++) {
            for (let len = k; len <= k; len++) {
                const sum = dp[i][j][len - 1];
                if (sum > maxSum) {
                    maxSum = sum;
                    result = [i, j, j + len - 1];
                } else if (sum === maxSum && [i, j, j + len - 1].join() < result.join()) {
                    result = [i, j, j + len - 1];
                }
            }
        }
    }
    
    return result.slice(1); // remove the first index (0-based)
    
};