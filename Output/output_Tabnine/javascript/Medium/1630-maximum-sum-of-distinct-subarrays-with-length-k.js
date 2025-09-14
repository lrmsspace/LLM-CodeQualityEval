/**https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/ */
//You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
//	The length of the subarray is k, and
//	All the elements of the subarray are distinct.
//Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,5,4,2,9,9,9], k = 3
//Output: 15
//Explanation: The subarrays of nums with length 3 are:
//- [1,5,4] which meets the requirements and has a sum of 10.
//- [5,4,2] which meets the requirements and has a sum of 11.
//- [4,2,9] which meets the requirements and has a sum of 15.
//- [2,9,9] which does not meet the requirements because the element 9 is repeated.
//- [9,9,9] which does not meet the requirements because the element 9 is repeated.
//We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
//Example 2:
//Input: nums = [4,4,4], k = 3
//Output: 0
//Explanation: The subarrays of nums with length 3 are:
//- [4,4,4] which does not meet the requirements because the element 4 is repeated.
//We return 0 because no subarrays meet the conditions.
// 
//Constraints:
//	1 <= k <= nums.length <= 105
//	1 <= nums[i] <= 105
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumSubarraySum = function(nums, k) {
    let n = nums.length;
    if (n < k) return 0;
    
    let maxSum = 0;
    let sum = 0;
    let map = new Map();
    
    for (let i = 0; i < k; i++) {
        sum += nums[i];
        map.set(nums[i], (map.get(nums[i]) || 0) + 1);
    }
    maxSum = Math.max(maxSum, sum);
    
    for (let i = k; i < n; i++) {
        sum -= nums[i - k];
        sum += nums[i];
        
        if (map.get(nums[i - k]) === 1) {
            map.delete(nums[i - k]);
        } else {
            map.set(nums[i - k], map.get(nums[i - k]) - 1);
        }
        
        maxSum = Math.max(maxSum, sum);
    }
    
    return maxSum;
    
};