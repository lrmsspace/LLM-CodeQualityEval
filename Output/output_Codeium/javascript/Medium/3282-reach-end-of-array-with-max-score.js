/*
 You are given an integer array nums of length n.
 Your goal is to start at index 0 and reach index n - 1. You can only jump to indices greater than your current index.
 The score for a jump from index i to index j is calculated as (j - i) * nums[i].
 Return the maximum possible total score by the time you reach the last index.
 Example 1:
 Input: nums = [1,3,1,5]
 Output: 7
 Explanation:
 First, jump to index 1 and then jump to the last index. The final score is 1 * 1 + 2 * 3 = 7.
 Example 2:
 Input: nums = [4,3,1,3,2]
 Output: 16
 Explanation:
 Jump directly to the last index. The final score is 4 * 4 = 16.
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 105
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaximumScore = function(nums) {
    let dp = new Array(nums.length).fill(0);
    dp[0] = nums[0];
    let maxScore = dp[0];
    for (let i = 1; i < nums.length; i++) {
        dp[i] = Math.max(dp[i-1], (i > 0 ? dp[i-1] : 0) + nums[i] * (nums.length - 1 - i));
        maxScore = Math.max(maxScore, dp[i]);
    }
    return maxScore;
};