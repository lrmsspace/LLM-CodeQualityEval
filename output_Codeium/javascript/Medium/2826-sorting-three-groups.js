/*
 You are given an integer array nums. Each element in nums is 1, 2 or 3. In each operation, you can remove an element from nums. Return the minimum number of operations to make nums non-decreasing.
 Example 1:
 Input: nums = [2,1,3,2,1]
 Output: 3
 Explanation:
 One of the optimal solutions is to remove nums[0], nums[2] and nums[3].
 Example 2:
 Input: nums = [1,3,2,1,3,3]
 Output: 2
 Explanation:
 One of the optimal solutions is to remove nums[1] and nums[2].
 Example 3:
 Input: nums = [2,2,2,2,3,3]
 Output: 0
 Explanation:
 nums is already non-decreasing.
 Constraints:
 1 <= nums.length <= 100
 1 <= nums[i] <= 3
 Follow-up: Can you come up with an algorithm that runs in O(n) time complexity?
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function(nums) {
    let count1 = 0, count2 = 0, count3 = 0;

    // Count the occurrences of 1, 2, and 3
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] == 1) count1++;
        else if (nums[i] == 2) count2++;
        else if (nums[i] == 3) count3++;
    }

    // Calculate the minimum operations needed to make nums non-decreasing
    let remove1 = nums.length - count1; // Remove all 2s and 3s
    let remove2 = nums.length - count2; // Remove all 1s and 3s
    let remove3 = nums.length - count3; // Remove all 1s and 2s

    return nums.length - (count1 + count2 + count3 - Math.max(remove1, Math.max(remove2, remove3)));
};