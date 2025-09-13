/*
 You are given an integer array nums and a positive integer k.
 A subsequence sub of nums with length x is called valid if it satisfies:
 (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
 Return the length of the longest valid subsequence of nums.
 Example 1:
 Input: nums = [1,2,3,4,5], k = 2
 Output: 5
 Explanation:
 The longest valid subsequence is [1, 2, 3, 4, 5].
 Example 2:
 Input: nums = [1,4,2,3,1,4], k = 3
 Output: 4
 Explanation:
 The longest valid subsequence is [1, 4, 1, 4].
 Constraints:
 2 <= nums.length <= 103
 1 <= nums[i] <= 107
 1 <= k <= 103
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
        for (let j = 1; j <= k; j++) {
            dp[i][j] = 1;
            for (let l = i - 1; l >= 0; l--) {
                const diff = (nums[i] - nums[l] + k) % k;
                if (diff === j) {
                    dp[i][j] = Math.max(dp[i][j], dp[l][diff] + 1);
                }
            }
            maxLen = Math.max(maxLen, dp[i][j]);
        }
    }
    
    return maxLen;    
};