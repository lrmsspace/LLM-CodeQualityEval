/**https://leetcode.com/problems/largest-sum-of-averages/ */
//You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.
//Note that the partition must use every integer in nums, and that the score is not necessarily an integer.
//Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.
// 
//Example 1:
//Input: nums = [9,1,2,3,9], k = 3
//Output: 20.00000
//Explanation: 
//The best choice is to partition nums into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
//We could have also partitioned nums into [9, 1], [2], [3, 9], for example.
//That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
//Example 2:
//Input: nums = [1,2,3,4,5,6,7], k = 4
//Output: 20.50000
// 
//Constraints:
//	1 <= nums.length <= 100
//	1 <= nums[i] <= 104
//	1 <= k <= nums.length
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var largestSumOfAverages = function(nums, k) {
    let n = nums.length;

    let dp = new Array(n).fill(0).map(() => new Array(k + 1).fill(0));

    for (let i = 0; i < n; i++) {
        dp[i][1] = nums.slice(0, i + 1).reduce((a, b) => a + b) / (i + 1);
    }

    for (let i = 1; i < n; i++) {
        for (let j = 2; j <= k; j++) {
            for (let l = 0; l < i; l++) {
                dp[i][j] = Math.max(dp[i][j], dp[l][j - 1] + (nums.slice(l + 1, i + 1)))
            }
        }
    }
    return dp[n - 1][k];
};