/*
 You are given an array of integers nums. Some values in nums are missing and are denoted by -1.
 You must choose a pair of positive integers (x, y) exactly once and replace each missing element with either x or y.
 You need to minimize the maximum absolute difference between adjacent elements of nums after replacements.
 Return the minimum possible difference.
 Example 1:
 Input: nums = [1,2,-1,10,8]
 Output: 4
 Explanation:
 By choosing the pair as (6, 7), nums can be changed to [1, 2, 6, 10, 8].
 The absolute differences between adjacent elements are:
 |1 - 2| == 1
 |2 - 6| == 4
 |6 - 10| == 4
 |10 - 8| == 2
 Example 2:
 Input: nums = [-1,-1,-1]
 Output: 0
 Explanation:
 By choosing the pair as (4, 4), nums can be changed to [4, 4, 4].
 Example 3:
 Input: nums = [-1,10,-1,8]
 Output: 1
 Explanation:
 By choosing the pair as (11, 9), nums can be changed to [11, 10, 9, 8].
 Constraints:
 2 <= nums.length <= 105
 nums[i] is either -1 or in the range [1, 109].
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var minDifference = function(nums) {
    const n = nums.length;
    let left = 0;
    let right = 0;
    let minDiff = Infinity;

    // Find the first and last non-negative elements
    while (right < n && nums[right] === -1) {
        right++;
    }
    left = right;

    while (right < n) {
        // If we encounter a non-negative element, we can calculate the difference
        if (nums[right] !== -1) {
            minDiff = Math.min(minDiff, Math.abs(nums[right] - nums[left]));
            left = right;
        }
        right++;
    }

    return minDiff === Infinity ? 0 : minDiff;
};