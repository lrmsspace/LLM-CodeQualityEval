/*
 You are given an integer array nums.
 You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:
 All elements in the subarray are unique.
 The sum of the elements in the subarray is maximized.
 Return the maximum sum of such a subarray.
 Example 1:
 Input: nums = [1,2,3,4,5]
 Output: 15
 Explanation:
 Select the entire array without deleting any element to obtain the maximum sum.
 Example 2:
 Input: nums = [1,1,0,1,1]
 Output: 1
 Explanation:
 Delete the element nums[0] == 1, nums[1] == 1, nums[2] == 0, and nums[3] == 1. Select the entire array [1] to obtain the maximum sum.
 Example 3:
 Input: nums = [1,2,-1,-2,1,0,-1]
 Output: 3
 Explanation:
 Delete the elements nums[2] == -1 and nums[3] == -2, and select the subarray [2, 1] from [1, 2, 1, 0, -1] to obtain the maximum sum.
 Constraints:
 1 <= nums.length <= 100
 -100 <= nums[i] <= 100
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSum = function(nums) {
    let maxSum = 0;
    let currentSum = 0;
    let currentSet = new Set();
    let maxSumWithoutDuplicates = 0;
    let currentSumWithoutDuplicates = 0;
    let currentSetWithoutDuplicates = new Set();
    
    for (let i = 0; i < nums.length; i++) {
        if (currentSet.has(nums[i])) {
            maxSum = Math.max(maxSum, currentSum);
            currentSum = currentSum - nums[i - 1];
            for (let num of currentSet) {
                if (num !== nums[i - 1]) {
                    currentSetWithoutDuplicates.add(num);
                    currentSumWithoutDuplicates += num;
                }
            }
            currentSet = new Set();
            currentSum = 0;
        }
        currentSet.add(nums[i]);
        currentSum += nums[i];
        if (currentSetWithoutDuplicates.has(nums[i])) {
            maxSumWithoutDuplicates = Math.max(maxSumWithoutDuplicates, currentSumWithoutDuplicates);
            currentSumWithoutDuplicates = currentSumWithoutDuplicates - nums[i - 1];
            for (let num of currentSetWithoutDuplicates) {
                if (num !== nums[i - 1]) {
                    currentSetWithoutDuplicates.add(num);
                    currentSumWithoutDuplicates += num;
                }
            }
            currentSetWithoutDuplicates = new Set();
            currentSumWithoutDuplicates = 0;
        }
        currentSetWithoutDuplicates.add(nums[i]);
        currentSumWithoutDuplicates += nums[i];
    }
    
    maxSum = Math.max(maxSum, currentSum);
    maxSumWithoutDuplicates = Math.max(maxSumWithoutDuplicates, currentSumWithoutDuplicates);
    
    return Math.max(maxSum, maxSumWithoutDuplicates);
    
};