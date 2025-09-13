/**https://leetcode.com/problems/subarray-sums-divisible-by-k/ */
//Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [4,5,0,-2,-3,1], k = 5
//Output: 7
//Explanation: There are 7 subarrays with a sum divisible by k = 5:
//[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
//Example 2:
//Input: nums = [5], k = 9
//Output: 0
// 
//Constraints:
//	1 <= nums.length <= 3 * 104
//	-104 <= nums[i] <= 104
//	2 <= k <= 104
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysDivByK = function(nums, k) {
    const prefixSums = new Array(nums.length + 1).fill(0);
    for (let i = 1; i <= nums.length; i++) {
        prefixSums[i] = (prefixSums[i - 1] + nums[i - 1]) % k;
    }
    
    const count = new Map();
    count.set(0, 1);
    
    let result = 0;
    for (let i = 1; i <= nums.length; i++) {
        const remainder = prefixSums[i] % k;
        const complement = (k - remainder) % k;
        result += count.get(complement) || 0;
        count.set(remainder, (count.get(remainder) || 0) + 1);
    }
    
    return result;
    
};