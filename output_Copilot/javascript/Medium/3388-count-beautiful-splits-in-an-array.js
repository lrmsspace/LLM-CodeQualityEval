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
    const n = nums.length;
    let count = 0;

    // Iterate through all possible split points
    for (let i = 1; i < n - 1; i++) {
        // Check if nums[0..i] is a prefix of nums[i+1..j] or nums[i+1..j] is a prefix of nums[j+1..n-1]
        for (let j = i + 1; j < n; j++) {
            const nums1 = nums.slice(0, i);
            const nums2 = nums.slice(i, j);
            const nums3 = nums.slice(j);

            if (nums1.length > 0 && (nums2.length >= nums1.length && nums2.slice(0, nums1.length).every((val, idx) => val === nums1[idx]))) {
                count++;
            } else if (nums2.length > 0 && (nums3.length >= nums2.length && nums3.slice(0, nums2.length).every((val, idx) => val === nums2[idx]))) {
                count++;
            }
        }
    }

    return count;    
};