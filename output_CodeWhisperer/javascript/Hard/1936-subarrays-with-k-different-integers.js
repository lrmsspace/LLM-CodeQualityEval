/**https://leetcode.com/problems/subarrays-with-k-different-integers/ */
//Given an integer array nums and an integer k, return the number of good subarrays of nums.
//A good array is an array where the number of different integers in that array is exactly k.
//	For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [1,2,1,2,3], k = 2
//Output: 7
//Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
//Example 2:
//Input: nums = [1,2,1,3,4], k = 3
//Output: 3
//Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i], k <= nums.length
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysWithKDistinct = function(nums, k) {
    let n = nums.length;
    let count = 0;
    let left = 0;
    let right = 0;
    let map = new Map();
    while (right < n) {
        map.set(nums[right], (map.get(nums[right]) || 0) + 1);
        while (map.size > k) {
            map.set(nums[left], map.get(nums[left]) - 1);
            if (map.get(nums[left]) === 0) {
                map.delete(nums[left]);
            }
            left++;
        }
        if (map.size === k) {
            let temp = left;
            while (map.get(nums[temp]) > 1) {
                map.set(nums[temp], map.get(nums[temp]) - 1);
                temp++;
            }
            count += temp - left + 1;
        }
        right++;
    }
    return count;
};