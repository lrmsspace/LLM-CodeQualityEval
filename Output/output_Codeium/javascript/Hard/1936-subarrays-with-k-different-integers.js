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
    let count = 0;
    const seen = new Map();
    let left = 0;

    for (let right = 0; right < nums.length; right++) {
        if (seen.has(nums[right])) {
            seen.set(nums[right], seen.get(nums[right]) + 1);
        } else {
            seen.set(nums[right], 1);
        }

        while (seen.size > k) {
            seen.set(nums[left], seen.get(nums[left]) - 1);
            if (seen.get(nums[left]) === 0) {
                seen.delete(nums[left]);
            }
            left++;
        }

        count += right - left + 1;
    }

    return count;
};