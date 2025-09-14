/**https://leetcode.com/problems/longest-increasing-subsequence/ */
//Given an integer array nums, return the length of the longest strictly increasing subsequence.
// 
//Example 1:
//Input: nums = [10,9,2,5,3,7,101,18]
//Output: 4
//Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
//Example 2:
//Input: nums = [0,1,0,3,2,3]
//Output: 4
//Example 3:
//Input: nums = [7,7,7,7,7,7,7]
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 2500
//	-104 <= nums[i] <= 104
// 
//Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    let dp = [nums[0]];
    for(let i = 1; i < nums.length; i++){
        let index = binarySearch(dp, nums[i]);
        if(index === dp.length){
            dp.push(nums[i]);
        }else{
            dp[index] = nums[i];
        }
    }
    return dp.length;

};