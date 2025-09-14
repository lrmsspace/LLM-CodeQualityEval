/**https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/ */
//You are given an integer array nums. The value of this array is defined as the sum of |nums[i] - nums[i + 1]| for all 0 <= i < nums.length - 1.
//You are allowed to select any subarray of the given array and reverse it. You can perform this operation only once.
//Find maximum possible value of the final array.
// 
//Example 1:
//Input: nums = [2,3,1,5,4]
//Output: 10
//Explanation: By reversing the subarray [3,1,5] the array becomes [2,5,1,3,4] whose value is 10.
//Example 2:
//Input: nums = [2,4,9,24,2,1,10]
//Output: 68
// 
//Constraints:
//	2 <= nums.length <= 3 * 104
//	-105 <= nums[i] <= 105
//	The answer is guaranteed to fit in a 32-bit integer.
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxValueAfterReverse = function(nums) {
    let max = 0;
    let min = 0;
    let sum = 0;
    for(let i=0;i<nums.length-1;i++){
        max += Math.abs(nums[i]-nums[i+1]);
        min += Math.abs(nums[i]-nums[i+1]);
        sum += nums[i]+nums[i+1];
    }
    let max1 = Math.abs(nums[0]-nums[nums.length-1]);
    let max2 = Math.abs(nums[1]-nums[0]);
    let max3 = Math.abs(nums[nums.length-1]-nums[nums.length-2]);
    max = Math.max(max,max1,max2,max3);
    return sum-max;
};