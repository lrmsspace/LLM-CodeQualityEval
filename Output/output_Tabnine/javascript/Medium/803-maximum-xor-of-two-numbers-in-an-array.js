/**https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/ */
//Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
// 
//Example 1:
//Input: nums = [3,10,5,25,2,8]
//Output: 28
//Explanation: The maximum result is 5 XOR 25 = 28.
//Example 2:
//Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
//Output: 127
// 
//Constraints:
//	1 <= nums.length <= 2 * 105
//	0 <= nums[i] <= 231 - 1
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaximumXOR = function(nums) {
    let max = 0;
    const maxBit = Math.floor(Math.log2(Math.max(...nums)));
    
    for (let i = 0; i < (1 << maxBit); i++) {
        const left = maxBit - Math.floor(Math.log2(i)) - 1;
        const right = maxBit - Math.floor(Math.log2(i | (1 << left))) - 1;
        
        max = Math.max(max, nums[i] ^ (nums[right] | (1 << left)));
    }
    
    return max;
    
};