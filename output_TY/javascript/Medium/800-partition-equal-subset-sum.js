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
    let sum = nums.reduce((a,b)=>a+b,0);
    if(sum%2!==0) return false;
    let target = sum/2;
    let dp = new Array(target+1).fill(false);
    dp[0] = true;
    for(let i=0;i<nums.length;i++){
        for(let j=target;j>=nums[i];j--){
            dp[j] = dp[j]||dp[j-nums[i]];
        }
    }
    return dp[target];
};