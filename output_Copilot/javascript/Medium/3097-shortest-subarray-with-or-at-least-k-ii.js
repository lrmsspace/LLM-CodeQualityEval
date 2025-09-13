/*
 You are given an array nums of non-negative integers and an integer k.
 An array is called special if the bitwise OR of all of its elements is at least k.
 Return the length of the shortest special non-empty subarray of nums, or return -1 if no special subarray exists.
 Example 1:
 Input: nums = [1,2,3], k = 2
 Output: 1
 Explanation:
 The subarray [3] has OR value of 3. Hence, we return 1.
 Example 2:
 Input: nums = [2,1,8], k = 10
 Output: 3
 Explanation:
 The subarray [2,1,8] has OR value of 11. Hence, we return 3.
 Example 3:
 Input: nums = [1,2], k = 0
 Output: 1
 Explanation:
 The subarray [1] has OR value of 1. Hence, we return 1.
 Constraints:
 1 <= nums.length <= 2 * 105
 0 <= nums[i] <= 109
 0 <= k <= 109
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minimumSubarrayLength = function(nums, k) {
    const n = nums.length;
    let left = 0;
    let right = 0;
    let currentOR = 0;
    let minLength = Infinity;

    while (right < n) {
        // Expand the window by including nums[right]
        currentOR |= nums[right];
        right++;

        // Contract the window from the left as long as the condition is met
        while (currentOR >= k) {
            minLength = Math.min(minLength, right - left);
            currentOR ^= nums[left];
            left++;
        }
    }

    return minLength === Infinity ? -1 : minLength;
};