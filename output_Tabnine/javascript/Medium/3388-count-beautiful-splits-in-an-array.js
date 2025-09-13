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
    let count = 0;
    let sum = Array(n + 1).fill(0);
    
    for (let i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + nums[i - 1];
    }
    
    for (let i = 1; i < n; i++) {
        let midSum = (sum[n] - sum[i]) / 2;
        let leftSum = sum[i - 1];
        let rightSum = sum[n] - sum[i];
        
        if (leftSum === midSum && rightSum === midSum) {
            count++;
        }
    }
    
    return count;   
    
};