/*
 You are given an integer array nums and a non-negative integer k. A sequence of integers seq is called good if there are at most k indices i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].
 Return the maximum possible length of a good subsequence of nums.
 Example 1:
 Input: nums = [1,2,1,1,3], k = 2
 Output: 4
 Explanation:
 The maximum length subsequence is [1,2,1,1,3].
 Example 2:
 Input: nums = [1,2,3,4,5,1], k = 0
 Output: 2
 Explanation:
 The maximum length subsequence is [1,2,3,4,5,1].
 Constraints:
 1 <= nums.length <= 5 * 103
 1 <= nums[i] <= 109
 0 <= k <= min(50, nums.length)
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumLength = function(nums, k) {
    const n = nums.length;
    const dp = new Array(n).fill(0).map(() => new Array(k + 1).fill(0));
    
    let maxLen = 1;
    
    for (let i = 0; i < n; i++) {
        dp[i][0] = 1;
        for (let j = 0; j <= k; j++) {
            if (i === 0) continue;
            dp[i][j] = 1;
            for (let l = i - 1; l >= 0; l--) {
                if (nums[i] === nums[l]) {
                    dp[i][j] = Math.max(dp[i][j], dp[l][j] + 1);
                } else if (j > 0) {
                    dp[i][j] = Math.max(dp[i][j], dp[l][j - 1] + 1);
                }
            }
            maxLen = Math.max(maxLen, dp[i][j]);
        }
    }
    
    return maxLen;    
};