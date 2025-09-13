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
    let n = nums.length;
    let dp = Array.from({ length: n + 1 }, () => Array(k).fill(0));
    
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < k; j++) {
            dp[i + 1][j] = dp[i][j]; // Not taking nums[i]
            let newMod = (j + nums[i]) % k;
            dp[i + 1][newMod] = Math.max(dp[i + 1][newMod], dp[i][j] + 1); // Taking nums[i]
        }
    }
    
    return dp[n][0]; // The longest valid subsequence length    
};