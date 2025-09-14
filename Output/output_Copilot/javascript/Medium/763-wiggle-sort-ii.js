/**https://leetcode.com/problems/wiggle-sort-ii/ */
//Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//You may assume the input array always has a valid answer.
// 
//Example 1:
//Input: nums = [1,5,1,1,6,4]
//Output: [1,6,1,5,1,4]
//Explanation: [1,4,1,5,1,6] is also accepted.
//Example 2:
//Input: nums = [1,3,2,2,3,1]
//Output: [2,3,1,3,1,2]
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	0 <= nums[i] <= 5000
//	It is guaranteed that there will be an answer for the given input nums.
// 
//Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var wiggleSort = function(nums) {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const mid = Math.floor((n + 1) / 2);
    const left = nums.slice(0, mid).reverse();
    const right = nums.slice(mid).reverse();
    for (let i = 0; i < n; i++) {
        nums[i] = i % 2 === 0 ? left[Math.floor(i / 2)] : right[Math.floor(i / 2)];
    }  
    return nums; // Return the modified array (not necessary, but for clarity)  
};