/*
 You are given an integer array nums and two integers k and numOperations.
 You must perform an operation numOperations times on nums, where in each operation you:
 Select an index i that was not selected in any previous operations.
 Add an integer in the range [-k, k] to nums[i].
 Return the maximum possible frequency of any element in nums after performing the operations.
 Example 1:
 Input: nums = [1,4,5], k = 1, numOperations = 2
 Output: 2
 Explanation:
 We can achieve a maximum frequency of two by:
 Adding 0 to nums[1]. nums becomes [1, 4, 5].
 Adding -1 to nums[2]. nums becomes [1, 4, 4].
 Example 2:
 Input: nums = [5,11,20,20], k = 5, numOperations = 1
 Output: 2
 Explanation:
 We can achieve a maximum frequency of two by:
 Adding 0 to nums[1].
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 105
 0 <= k <= 105
 0 <= numOperations <= nums.length
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} numOperations
 * @return {number}
 */
var maxFrequency = function(nums, k, numOperations) {
    const n = nums.length;
    nums.sort((a, b) => a - b);
    
    let left = 0, right = 0, operationsUsed = 0, maxFreq = 0;

    while (right < n) {
        // Calculate the cost to make all elements from left to right equal to nums[right]
        operationsUsed += (nums[right] - nums[left]) * (right - left);
        
        // If we exceed the allowed number of operations, move the left pointer
        while (operationsUsed > numOperations) {
            operationsUsed -= (nums[right] - nums[left]);
            left++;
        }
        
        // Update the maximum frequency
        maxFreq = Math.max(maxFreq, right - left + 1);
        
        // Move the right pointer
        right++;
    }

    return maxFreq;
        
};