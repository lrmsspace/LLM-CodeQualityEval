/**https://leetcode.com/problems/smallest-range-ii/ */
//You are given an integer array nums and an integer k.
//For each index i where 0 <= i < nums.length, change nums[i] to be either nums[i] + k or nums[i] - k.
//The score of nums is the difference between the maximum and minimum elements in nums.
//Return the minimum score of nums after changing the values at each index.
// 
//Example 1:
//Input: nums = [1], k = 0
//Output: 0
//Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
//Example 2:
//Input: nums = [0,10], k = 2
//Output: 6
//Explanation: Change nums to be [2, 8]. The score is max(nums) - min(nums) = 8 - 2 = 6.
//Example 3:
//Input: nums = [1,3,6], k = 3
//Output: 3
//Explanation: Change nums to be [4, 6, 3]. The score is max(nums) - min(nums) = 6 - 3 = 3.
// 
//Constraints:
//	1 <= nums.length <= 104
//	0 <= nums[i] <= 104
//	0 <= k <= 104
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var smallestRangeII = function(nums, k) {
    nums.sort((a, b) => a - b);
    let left = 0, right = nums.length - 1;
    let minDiff = nums[right] - nums[left];
    while (right > left) {
        let mid = nums[left] + k;
        let r = nums[right] - k;
        minDiff = Math.min(minDiff, Math.max(mid, r) - Math.min(mid, r));
        if (nums[right] - k > nums[left] + k) {
            left++;
        } else {
            right--;
        }
    }
    return minDiff;
};