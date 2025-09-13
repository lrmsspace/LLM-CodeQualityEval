/**https://leetcode.com/problems/contiguous-array/ */
//Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
// 
//Example 1:
//Input: nums = [0,1]
//Output: 2
//Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
//Example 2:
//Input: nums = [0,1,0]
//Output: 2
//Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
// 
//Constraints:
//	1 <= nums.length <= 105
//	nums[i] is either 0 or 1.
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxLength = function(nums) {
    let maxLength = 0;
    let count = 0;
    const map = new Map();
    map.set(0, -1); // Initialize the map with count 0 at index -1

    for (let i = 0; i < nums.length; i++) {
        count += nums[i] === 1 ? 1 : -1; // Increment count for 1, decrement for 0

        if (map.has(count)) {
            maxLength = Math.max(maxLength, i - map.get(count)); // Update maxLength
        } else {
            map.set(count, i); // Store the first occurrence of this count
        }
    }

    return maxLength;    
};