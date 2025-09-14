/**https://leetcode.com/problems/maximum-gap/ */
//Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
//You must write an algorithm that runs in linear time and uses linear extra space.
// 
//Example 1:
//Input: nums = [3,6,9,1]
//Output: 3
//Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
//Example 2:
//Input: nums = [10]
//Output: 0
//Explanation: The array contains less than 2 elements, therefore return 0.
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 109
/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumGap = function(nums) {
    if (nums.length < 2) return 0;
    let min = nums[0];
    let max = nums[0];
    for (let i = 1; i < nums.length; i++) {
        min = Math.min(min, nums[i]);
        max = Math.max(max, nums[i]);
    }
    if (max - min === 0) return 0;
    let gap = Math.ceil((max - min) / (nums.length - 1));
    let maxGap = 0;
    let prev = min;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] - prev >= gap) {
            maxGap = Math.max(maxGap, nums[i] - prev);
            prev = nums[i];
        }
    }
    return maxGap;
};