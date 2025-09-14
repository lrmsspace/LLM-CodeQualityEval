/**https://leetcode.com/problems/move-zeroes/ */
//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//Note that you must do this in-place without making a copy of the array.
// 
//Example 1:
//Input: nums = [0,1,0,3,12]
//Output: [1,3,12,0,0]
//Example 2:
//Input: nums = [0]
//Output: [0]
// 
//Constraints:
//	1 <= nums.length <= 104
//	-231 <= nums[i] <= 231 - 1
// 
//Follow up: Could you minimize the total number of operations done?
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let lastNonZeroFoundAt = 0; // Pointer for the position of the last non-zero element
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== 0) {
            nums[lastNonZeroFoundAt] = nums[i]; // Move non-zero element to the last non-zero position
            lastNonZeroFoundAt++;
        }
    }
    for (let i = lastNonZeroFoundAt; i < nums.length; i++) {
        nums[i] = 0; // Fill the remaining positions with zeros
    }   
    return nums; // Return the modified array (not necessary, but for clarity) 
};