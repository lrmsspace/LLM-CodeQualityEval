/**https://leetcode.com/problems/shortest-unsorted-continuous-subarray/ */
//Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
//Return the shortest such subarray and output its length.
// 
//Example 1:
//Input: nums = [2,6,4,8,10,9,15]
//Output: 5
//Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
//Example 2:
//Input: nums = [1,2,3,4]
//Output: 0
//Example 3:
//Input: nums = [1]
//Output: 0
// 
//Constraints:
//	1 <= nums.length <= 104
//	-105 <= nums[i] <= 105
// 
//Follow up: Can you solve it in O(n) time complexity?
/**
 * @param {number[]} nums
 * @return {number}
 */
var findUnsortedSubarray = function(nums) {
    let n = nums.length;
    let left = n - 1, right = 0;
    let minRight = nums[n - 1], maxLeft = nums[0];
    
    for (let i = 1; i < n; i++) {
        maxLeft = Math.min(maxLeft, nums[i]);
        if (nums[i] < maxLeft) {
            right = i;
        }
    }
    
    for (let i = n - 2; i >= 0; i--) {
        minRight = Math.max(minRight, nums[i]);
        if (nums[i] > minRight) {
            left = i;
        }
    }
    
    return right - left > 0? right - left + 1 : 0;
    
};