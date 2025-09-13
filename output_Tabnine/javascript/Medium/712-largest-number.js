/**https://leetcode.com/problems/largest-number/ */
//Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
//Since the result may be very large, so you need to return a string instead of an integer.
// 
//Example 1:
//Input: nums = [10,2]
//Output: "210"
//Example 2:
//Input: nums = [3,30,34,5,9]
//Output: "9534330"
// 
//Constraints:
//	1 <= nums.length <= 100
//	0 <= nums[i] <= 109
/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    // Sort the numbers in descending order first
    nums.sort((a, b) => {
        return `${b}${a}` - `${a}${b}`;
    });
    
    // If all numbers are zero, return "0"
    if (nums[0] === 0) {
        return "0";
    }
    
    // Return the largest number
    return nums.join("");
    
};