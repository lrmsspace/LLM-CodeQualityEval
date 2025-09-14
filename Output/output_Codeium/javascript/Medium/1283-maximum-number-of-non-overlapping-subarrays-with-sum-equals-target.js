/**https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/ */
//Given an array nums and an integer target, return the maximum number of non-empty non-overlapping subarrays such that the sum of values in each subarray is equal to target.
// 
//Example 1:
//Input: nums = [1,1,1,1,1], target = 2
//Output: 2
//Explanation: There are 2 non-overlapping subarrays [1,1,1,1,1] with sum equals to target(2).
//Example 2:
//Input: nums = [-1,3,5,1,4,2,-9], target = 6
//Output: 2
//Explanation: There are 3 subarrays with sum equal to 6.
//([5,1], [4,2], [3,5,1,4,2,-9]) but only the first 2 are non-overlapping.
// 
//Constraints:
//	1 <= nums.length <= 105
//	-104 <= nums[i] <= 104
//	0 <= target <= 106
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var maxNonOverlapping = function(nums, target) {
    let dp = new Array(nums.length).fill(0).map(() => new Array(2).fill(0));
    let sum = 0;
    let res = 0;
    for (let i = 0; i < nums.length; i++) {
        sum += nums[i];
        if (sum === target) res++;
        if (dp[i-1][1] && sum - dp[i-1][1] === target) res++;
        dp[i][0] = sum;
        dp[i][1] = Math.max(dp[i-1][1], dp[i-1][0]);
    }
    return res;
};