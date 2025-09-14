/**https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/ */
//You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.
//We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:
//	The subarray consists of exactly 2, equal elements. For example, the subarray [2,2] is good.
//	The subarray consists of exactly 3, equal elements. For example, the subarray [4,4,4] is good.
//	The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
//Return true if the array has at least one valid partition. Otherwise, return false.
// 
//Example 1:
//Input: nums = [4,4,4,5,6]
//Output: true
//Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6].
//This partition is valid, so we return true.
//Example 2:
//Input: nums = [1,1,1,2]
//Output: false
//Explanation: There is no valid partition for this array.
// 
//Constraints:
//	2 <= nums.length <= 105
//	1 <= nums[i] <= 106
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var validPartition = function(nums) {
    const n = nums.length;
    if (n < 3) return false;
    
    // Initialize prefix sums
    const prefixSums = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        prefixSums[i] = prefixSums[i - 1] + nums[i - 1];
    }
    
    // Check for valid partitions
    for (let i = 2; i <= n - 2; i++) {
        // Check if the prefix sums form a valid partition
        if (prefixSums[i] === prefixSums[i - 1] && prefixSums[i] === prefixSums[i - 2]) {
            return true;
        }
        
        // Check if the prefix sums form a valid partition with consecutive increasing elements
        if (prefixSums[i] - prefixSums[i - 1] === prefixSums[i - 1] - prefixSums[i - 2]) {
            return true;
        }
    }
    
    return false;
    
};