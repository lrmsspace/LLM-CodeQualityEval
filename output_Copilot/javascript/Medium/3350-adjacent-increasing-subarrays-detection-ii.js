/*
 Given an array nums of n integers, your task is to find the maximum value of k for which there exist two adjacent subarrays of length k each, such that both subarrays are strictly increasing. Specifically, check if there are two subarrays of length k starting at indices a and b (a < b), where:
 Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
 The subarrays must be adjacent, meaning b = a + k.
 Return the maximum possible value of k.
 A subarray is a contiguous non-empty sequence of elements within an array.
 Example 1:
 Input: nums = [2,5,7,8,9,2,3,4,3,1]
 Output: 3
 Explanation:
 The subarray starting at index 2 is [7, 8, 9], which is strictly increasing.
 The subarray starting at index 5 is [2, 3, 4], which is also strictly increasing.
 These two subarrays are adjacent, and 3 is the maximum possible value of k for which two such adjacent strictly increasing subarrays exist.
 Example 2:
 Input: nums = [1,2,3,4,4,4,4,5,6,7]
 Output: 2
 Explanation:
 The subarray starting at index 0 is [1, 2], which is strictly increasing.
 The subarray starting at index 2 is [3, 4], which is also strictly increasing.
 These two subarrays are adjacent, and 2 is the maximum possible value of k for which two such adjacent strictly increasing subarrays exist.
 Constraints:
 2 <= nums.length <= 2 * 105
 -109 <= nums[i] <= 109
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxIncreasingSubarrays = function(nums) {
    const n = nums.length;
    let maxK = 0;

    // Create an array to store the lengths of increasing subarrays
    const incLengths = new Array(n).fill(1);

    // Calculate lengths of strictly increasing subarrays
    for (let i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
            incLengths[i] = incLengths[i - 1] + 1;
        }
    }

    // Check for adjacent increasing subarrays
    for (let i = 0; i < n - 1; i++) {
        if (incLengths[i] > 1 && incLengths[i + 1] > 1) {
            const k = Math.min(incLengths[i], incLengths[i + 1]);
            maxK = Math.max(maxK, k);
        }
    }

    return maxK;    
};