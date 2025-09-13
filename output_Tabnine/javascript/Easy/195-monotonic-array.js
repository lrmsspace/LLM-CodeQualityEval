/**https://leetcode.com/problems/monotonic-array/ */
//An array is monotonic if it is either monotone increasing or monotone decreasing.
//An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
//Given an integer array nums, return true if the given array is monotonic, or false otherwise.
// 
//Example 1:
//Input: nums = [1,2,2,3]
//Output: true
//Example 2:
//Input: nums = [6,5,4,4]
//Output: true
//Example 3:
//Input: nums = [1,3,2]
//Output: false
// 
//Constraints:
//	1 <= nums.length <= 105
//	-105 <= nums[i] <= 105
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isMonotonic = function(nums) {
    //if the array has less than two elements, it is monotonic
    if (nums.length < 2) return true;
    
    //check if the array is increasing
    let increasing = nums[1] > nums[0];
    
    //check if the array is decreasing
    let decreasing = nums[1] < nums[0];
    
    //check if the array is increasing or decreasing
    for(let i = 1; i < nums.length; i++) {
        if ((increasing && nums[i] <= nums[i - 1]) || (decreasing && nums[i] >= nums[i - 1])) {
            return false;
        }
    }
    
    return true;
    

};