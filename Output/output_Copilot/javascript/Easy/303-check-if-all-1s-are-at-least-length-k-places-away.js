/**https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/ */
//Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.
// 
//Example 1:
//Input: nums = [1,0,0,0,1,0,0,1], k = 2
//Output: true
//Explanation: Each of the 1s are at least 2 places away from each other.
//Example 2:
//Input: nums = [1,0,0,1,0,1], k = 2
//Output: false
//Explanation: The second 1 and third 1 are only one apart from each other.
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= k <= nums.length
//	nums[i] is 0 or 1
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var kLengthApart = function(nums, k) {
    let lastOne = -1; // Initialize the index of the last 1 to -1 (not found yet)
    for (let i = 0; i < nums.length; i++) { // Iterate through the array
        if (nums[i] === 1) { // If we find a 1
            if (lastOne !== -1 && i - lastOne <= k) { // Check if it's too close to the last one
                return false; // If so, return false
            }
            lastOne = i; // Update the index of the last 1
        }
    }
    return true; // If we finish the loop without finding any close 1s, return true    
};