/*
 You are given an array nums.
 A split of an array nums is beautiful if:
 The array nums is split into three subarrays: nums1, nums2, and nums3, such that nums can be formed by concatenating nums1, nums2, and nums3 in that order.
 The subarray nums1 is a prefix of nums2 OR nums2 is a prefix of nums3.
 Return the number of ways you can make this split.
 Example 1:
 Input: nums = [1,1,2,1]
 Output: 2
 Explanation:
 The beautiful splits are:
 A split with nums1 = [1], nums2 = [1,2], nums3 = [1].
 A split with nums1 = [1], nums2 = [1], nums3 = [2,1].
 Example 2:
 Input: nums = [1,2,3,4]
 Output: 0
 Explanation:
 There are 0 beautiful splits.
 Constraints:
 1 <= nums.length <= 5000
 0 <= nums[i] <= 50
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var beautifulSplits = function(nums) {
    let n = nums.length;
    let left = new Array(n).fill(0);
    let right = new Array(n).fill(0);   
    for (let i = 0; i < n; i++) {
        if (i == 0) {
            left[i] = nums[i];
        } else {
            left[i] = Math.min(left[i - 1], nums[i]);
        }
    }
    for (let i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            right[i] = nums[i];
        } else {
            right[i] = Math.max(right[i + 1], nums[i]);
        }
    }
    for (let i = 1; i < n - 1; i++) {
        if (left[i - 1] < nums[i] && nums[i] < right[i + 1]) {
            res = Math.max(res, i + 1);
        }
    }
    return res;
    
};