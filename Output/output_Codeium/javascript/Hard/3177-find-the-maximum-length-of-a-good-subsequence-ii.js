/*
 You are given an integer array nums and a non-negative integer k. A sequence of integers seq is called good if there are at most k indices i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].
 Return the maximum possible length of a good subsequence of nums.
 Example 1:
 Input: nums = [1,2,1,1,3], k = 2
 Output: 4
 Explanation:
 The maximum length subsequence is [1,2,1,1,3].
 Example 2:
 Input: nums = [1,2,3,4,5,1], k = 0
 Output: 2
 Explanation:
 The maximum length subsequence is [1,2,3,4,5,1].
 Constraints:
 1 <= nums.length <= 5 * 103
 1 <= nums[i] <= 109
 0 <= k <= min(50, nums.length)
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumLength = function(nums, k) {
    let maxLen = 0;
    let left = 0;
    let count = 0;
    for (let right = 0; right < nums.length; right++) {
        if (right > 0 && nums[right] !== nums[right - 1]) {
            count++;
        }
        while (count > k) {
            if (nums[left] !== nums[left + 1]) {
                count--;
            }
            left++;
        }
        maxLen = Math.max(maxLen, right - left + 1);
    }
    return maxLen;
};