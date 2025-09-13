/**https://leetcode.com/problems/partition-equal-subset-sum/ */
//Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
// 
//Example 1:
//Input: nums = [1,5,11,5]
//Output: true
//Explanation: The array can be partitioned as [1, 5, 5] and [11].
//Example 2:
//Input: nums = [1,2,3,5]
//Output: false
//Explanation: The array cannot be partitioned into equal sum subsets.
// 
//Constraints:
//	1 <= nums.length <= 200
//	1 <= nums[i] <= 100
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
    let sum = nums.reduce((a, b) => a + b, 0);
    if (sum % 2!== 0) return false;
    let target = sum / 2;
    
    // dp[i][j] represents whether it is possible to get a subset sum of j using the first i numbers
    let dp = Array.from({ length: nums.length + 1 }, () => Array(target + 1).fill(false));
    dp[0][0] = true;
    
    // Initialize the first row
    for (let j = 1; j <= target; j++) {
        if (nums[0] === j) dp[1][j] = true;
    }
    
    // Fill the dp table
    for (let i = 2; i <= nums.length; i++) {
        for (let j = 1; j <= target; j++) {
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[nums.length][target];
    
};