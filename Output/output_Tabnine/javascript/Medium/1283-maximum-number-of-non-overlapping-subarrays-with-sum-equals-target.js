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
    const dp = Array(nums.length + 1).fill(0);
    const preSum = Array(nums.length + 1).fill(0);
    let maxCount = 0;
    
    preSum[0] = 0;
    for (let i = 1; i <= nums.length; i++) {
        preSum[i] = preSum[i - 1] + nums[i - 1];
    }
    
    for (let i = 1; i <= nums.length; i++) {
        for (let j = 0; j < i; j++) {
            if (preSum[i] - preSum[j] === target) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
                maxCount = Math.max(maxCount, dp[i]);
            }
        }
    }
    
    return maxCount;
    
};