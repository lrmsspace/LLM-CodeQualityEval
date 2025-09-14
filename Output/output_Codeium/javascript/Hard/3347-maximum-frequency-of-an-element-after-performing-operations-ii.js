/*
 You are given an integer array nums and two integers k and numOperations.
 You must perform an operation numOperations times on nums, where in each operation you:
 Select an index i that was not selected in any previous operations.
 Add an integer in the range [-k, k] to nums[i].
 Return the maximum possible frequency of any element in nums after performing the operations.
 Example 1:
 Input: nums = [1,4,5], k = 1, numOperations = 2
 Output: 2
 Explanation:
 We can achieve a maximum frequency of two by:
 Adding 0 to nums[1], after which nums becomes [1, 4, 5].
 Adding -1 to nums[2], after which nums becomes [1, 4, 4].
 Example 2:
 Input: nums = [5,11,20,20], k = 5, numOperations = 1
 Output: 2
 Explanation:
 We can achieve a maximum frequency of two by:
 Adding 0 to nums[1].
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 109
 0 <= k <= 109
 0 <= numOperations <= nums.length
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} numOperations
 * @return {number}
 */
var maxFrequency = function(nums, k, numOperations) {
    let n = nums.length;
    let prefixSum = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    let dp = new Array(n + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for (let i = n - 1; i >= 0; i--) {
        for (let j = 1; j <= Math.min(numOperations, n - i); j++) {
            let max = 0;
            for (let x = i; x < n; x++) {
                let avg = ~~((prefixSum[x + 1] - prefixSum[i]) / (x - i + 1));
                let left = k - avg;
                let right = k + avg;
                let l = Math.max(i, ~~(x - (right - nums[x])));
                let r = Math.min(x, ~~(x - (nums[x] - left)));
                max = Math.max(max, Math.min(x - i + 1, dp[l][j - 1] + r - l + 1));
            }
            dp[i][j] = max;
        }
    }
    return dp[0][numOperations];
};