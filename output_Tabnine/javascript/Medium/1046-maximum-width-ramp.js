/**https://leetcode.com/problems/maximum-width-ramp/ */
//A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
//Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.
// 
//Example 1:
//Input: nums = [6,0,8,2,1,5]
//Output: 4
//Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
//Example 2:
//Input: nums = [9,8,1,0,1,9,4,0,4,1]
//Output: 7
//Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
// 
//Constraints:
//	2 <= nums.length <= 5 * 104
//	0 <= nums[i] <= 5 * 104
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxWidthRamp = function(nums) {
    let n = nums.length;
    let right = new Array(n).fill(n);
    let stack = [];
    for (let i = n - 1; i >= 0; i--) {
        while (stack.length && nums[stack[stack.length - 1]] <= nums[i]) {
            stack.pop();
        }
        right[i] = stack.length === 0? n : stack[stack.length - 1];
    }
    
    let maxRampWidth = 0;
    stack = [];
    for (let i = 0; i < n; i++) {
        while (stack.length && nums[stack[stack.length - 1]] >= nums[i]) {
            maxRampWidth = Math.max(maxRampWidth, i - stack[stack.length - 1]);
            stack.pop();
        }
        stack.push(i);
    }
    
    return maxRampWidth;
    
};