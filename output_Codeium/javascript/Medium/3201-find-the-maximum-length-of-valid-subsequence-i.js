/*
 You are given an integer array nums.
 A subsequence sub of nums with length x is called valid if it satisfies:
 (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
 Return the length of the longest valid subsequence of nums.
 A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
 Example 1:
 Input: nums = [1,2,3,4]
 Output: 4
 Explanation:
 The longest valid subsequence is [1, 2, 3, 4].
 Example 2:
 Input: nums = [1,2,1,1,2,1,2]
 Output: 6
 Explanation:
 The longest valid subsequence is [1, 2, 1, 2, 1, 2].
 Example 3:
 Input: nums = [1,3]
 Output: 2
 Explanation:
 The longest valid subsequence is [1, 3].
 Constraints:
 2 <= nums.length <= 2 * 105
 1 <= nums[i] <= 107
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumLength = function(nums) {
    let dp = [1];
    let max = 1;
    for (let i = 1; i < nums.length; i++) {
        let curr = 1;
        for (let j = 0; j < i; j++) {
            if ((nums[i] + nums[j]) % 2 === 0) {
                curr = Math.max(curr, dp[j] + 1);
            }
        }
        dp.push(curr);
        max = Math.max(max, curr);
    }
    return max;
};