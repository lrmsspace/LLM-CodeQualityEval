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
    let dp = new Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        let j = i - 1;
        while (j >= 0 && nums[j] == nums[i]) {
            j--;
        }
        if (j == -1) {
            dp[i] = 1;
        } else {
            dp[i] = dp[j] + 1;
        }
        if (i - k >= 0) {
            dp[i] = Math.max(dp[i], dp[i - k] + 1);
        }
    }
    return dp[n - 1];
    
};