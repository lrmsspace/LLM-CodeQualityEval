/**https://leetcode.com/problems/single-number-iii/ */
//Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
//You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
// 
//Example 1:
//Input: nums = [1,2,1,3,2,5]
//Output: [3,5]
//Explanation:  [5, 3] is also a valid answer.
//Example 2:
//Input: nums = [-1,0]
//Output: [-1,0]
//Example 3:
//Input: nums = [0,1]
//Output: [1,0]
// 
//Constraints:
//	2 <= nums.length <= 3 * 104
//	-231 <= nums[i] <= 231 - 1
//	Each integer in nums will appear twice, only two integers will appear once.
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumber = function(nums) {
    let xor = nums.reduce((acc, val) => acc ^ val, 0);
    let diff = xor & (~(xor - 1));
    
    let firstNum = 0;
    for (let num of nums) {
        if (num & diff) {
            firstNum ^= num;
        }
    }
    
    return [firstNum, xor ^ firstNum];
    
};