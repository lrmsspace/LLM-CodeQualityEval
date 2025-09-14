/*
 You are given an array nums consisting of integers. You are also given a 2D array queries, where queries[i] = [posi, xi].
 For query i, we first set nums[posi] equal to xi, then we calculate the answer to query i which is the maximum sum of a subsequence of nums where no two adjacent elements are selected.
 Return the sum of the answers to all queries.
 Since the final answer may be very large, return it modulo 109 + 7.
 A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
 Example 1:
 Input: nums = [3,5,9], queries = [[1,-2],[0,-3]]
 Output: 21
 Explanation:
 After the 1st query, nums = [3,-2,9] and the maximum sum of a subsequence with non-adjacent elements is 3 + 9 = 12.
 After the 2nd query, nums = [-3,-2,9] and the maximum sum of a subsequence with non-adjacent elements is 9.
 Example 2:
 Input: nums = [0,-1], queries = [[0,-5]]
 Output: 0
 Explanation:
 After the 1st query, nums = [-5,-1] and the maximum sum of a subsequence with non-adjacent elements is 0 (choosing an empty subsequence).
 Constraints:
 1 <= nums.length <= 5 * 104
 -105 <= nums[i] <= 105
 1 <= queries.length <= 5 * 104
 queries[i] == [posi, xi]
 0 <= posi <= nums.length - 1
 -105 <= xi <= 105
*/

/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number}
 */
var maximumSumSubsequence = function(nums, queries) {
    const MOD = 10 ** 9 + 7;
    const n = nums.length;
    const dp = new Array(n + 1).fill(0);
    const prefixSum = new Array(n + 1).fill(0);
    
    for (let i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        dp[i] = Math.max(dp[i - 1], prefixSum[i]);
    }
    
    let result = 0;
    for (const [pos, x] of queries) {
        const left = Math.max(0, pos + 1);
        const right = Math.min(n, pos + x + 1);
        result = (result + dp[right] - dp[left]) % MOD;
    }
    
    return result;
    
};