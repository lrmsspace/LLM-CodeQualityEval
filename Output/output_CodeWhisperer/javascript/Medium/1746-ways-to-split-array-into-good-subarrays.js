/**https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/ */
//You are given a binary array nums.
//A subarray of an array is good if it contains exactly one element with the value 1.
//Return an integer denoting the number of ways to split the array nums into good subarrays. As the number may be too large, return it modulo 109 + 7.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [0,1,0,0,1]
//Output: 3
//Explanation: There are 3 ways to split nums into good subarrays:
//- [0,1] [0,0,1]
//- [0,1,0] [0,1]
//- [0,1,0,0] [1]
//Example 2:
//Input: nums = [0,1,0]
//Output: 1
//Explanation: There is 1 way to split nums into good subarrays:
//- [0,1,0]
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 1
/**
 * @param {number[]} nums
 * @return {number}
 */
var numberOfGoodSubarraySplits = function(nums) {
    let count = 1;
    let prev = -1;
    let mod = 1000000007;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === 1) {
            if (prev !== -1) {
                count = (count * (i - prev)) % mod;
            }
            prev = i;
        }
    }
    return prev === -1 ? 0 : count; 
};