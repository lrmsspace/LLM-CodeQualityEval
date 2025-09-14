/**https://leetcode.com/problems/next-greater-element-iii/ */
//Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
//Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
// 
//Example 1:
//Input: n = 12
//Output: 21
//Example 2:
//Input: n = 21
//Output: -1
// 
//Constraints:
//	1 <= n <= 231 - 1
/**
 * @param {number} n
 * @return {number}
 */
var nextGreaterElement = function(n) {
    
    let nums = n.toString().split('');
    let i = nums.length - 2;
    while(i >= 0 && nums[i] >= nums[i+1]) i--;
    if(i < 0) return -1;
    
    let j = nums.length - 1;
    while(j >= 0 && nums[j] <= nums[i]) j--;
    
    [nums[i], nums[j]] = [nums[j], nums[i]];
    
    return parseInt(nums.join('')) > n ? parseInt(nums.join('')) : -1;
    
};