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
    let count = 0;
    let prefixSum = 0;
    const map = {0: 1};
    for (const num of nums) {
        prefixSum += num;
        const mod = prefixSum % k;
        if (map[mod]) {
            count += map[mod];
        }
        map[mod] = (map[mod] || 0) + 1;
    }
    return count;   
    
};