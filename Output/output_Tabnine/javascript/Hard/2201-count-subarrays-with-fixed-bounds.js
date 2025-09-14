/**https://leetcode.com/problems/count-subarrays-with-fixed-bounds/ */
//You are given an integer array nums and two integers minK and maxK.
//A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
//	The minimum value in the subarray is equal to minK.
//	The maximum value in the subarray is equal to maxK.
//Return the number of fixed-bound subarrays.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
//Output: 2
//Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
//Example 2:
//Input: nums = [1,1,1,1], minK = 1, maxK = 1
//Output: 10
//Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
// 
//Constraints:
//	2 <= nums.length <= 105
//	1 <= nums[i], minK, maxK <= 106
/**
 * @param {number[]} nums
 * @param {number} minK
 * @param {number} maxK
 * @return {number}
 */
var countSubarrays = function(nums, minK, maxK) {
    const n = nums.length;
    let count = 0;
    const left = [];
    const right = [];
    
    for (let i = 0; i < n; i++) {
        if (nums[i] >= minK) left.push(i);
        if (nums[n - 1 - i] <= maxK) right.push(n - 1 - i);
    }
    
    for (let i = 0; i < left.length; i++) {
        count += right.length - right.indexOf(left[i]);
    }
    
    return count;
    
};