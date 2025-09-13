/**https://leetcode.com/problems/constrained-subsequence-sum/ */
//Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.
//A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.
// 
//Example 1:
//Input: nums = [10,2,-10,5,20], k = 2
//Output: 37
//Explanation: The subsequence is [10, 2, 5, 20].
//Example 2:
//Input: nums = [-1,-2,-3], k = 1
//Output: -1
//Explanation: The subsequence must be non-empty, so we choose the largest number.
//Example 3:
//Input: nums = [10,-2,-10,-5,20], k = 2
//Output: 23
//Explanation: The subsequence is [10, -2, -5, 20].
// 
//Constraints:
//	1 <= k <= nums.length <= 105
//	-104 <= nums[i] <= 104
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var constrainedSubsetSum = function(nums, k) {
    let n = nums.length;
    let dp = new Array(n).fill(0);
    let deque = [];
    let res = Number.MIN_SAFE_INTEGER;
    for (let i = 0; i < n; i++) {
        if (i > k && deque[0] === i - k - 1) {
            deque.shift();
        }
        dp[i] = nums[i] + (deque.length === 0 ? 0 : Math.max(0, dp[deque[0]]));
        while (deque.length > 0 && dp[deque[deque.length - 1]] < dp[i]) {
            deque.pop();
        }
        deque.push(i);
        res = Math.max(res, dp[i]);
    }
    return res;
};