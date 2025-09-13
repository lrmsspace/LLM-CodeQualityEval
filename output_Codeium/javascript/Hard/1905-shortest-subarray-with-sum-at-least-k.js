/**https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/ */
//Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [1], k = 1
//Output: 1
//Example 2:
//Input: nums = [1,2], k = 4
//Output: -1
//Example 3:
//Input: nums = [2,-1,2], k = 3
//Output: 3
// 
//Constraints:
//	1 <= nums.length <= 105
//	-105 <= nums[i] <= 105
//	1 <= k <= 109
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var shortestSubarray = function(nums, k) {
    let prefixSum = [0];
    for (let num of nums) {
        prefixSum.push(prefixSum[prefixSum.length - 1] + num);
    }
    let minLen = Infinity;
    for (let i = 0; i < prefixSum.length; i++) {
        for (let j = i + 1; j < prefixSum.length; j++) {
            if (prefixSum[j] - prefixSum[i] >= k) {
                minLen = Math.min(minLen, j - i);
                break;
            }
        }
    }
    return minLen === Infinity ? -1 : minLen;
    
};