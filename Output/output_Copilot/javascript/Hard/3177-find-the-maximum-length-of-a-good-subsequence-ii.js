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
    const n = nums.length;
    const freq = new Map();

    for (let i = 0; i < n; i++) {
        freq.set(nums[i], (freq.get(nums[i]) || 0) + 1);
    }

    const unique = Array.from(freq.keys());
    const m = unique.length;

    let left = 0;
    let right = 0;
    let maxLength = 0;

    while (right < m) {
        if (right - left + 1 - (freq.get(unique[right]) || 0) <= k) {
            maxLength = Math.max(maxLength, right - left + 1);
            right++;
        } else {
            left++;
        }
    }

    return maxLength;
};