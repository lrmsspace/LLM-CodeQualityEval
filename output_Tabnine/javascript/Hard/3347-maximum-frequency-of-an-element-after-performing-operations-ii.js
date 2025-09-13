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
 Adding 0 to nums[1], after which nums becomes [1, 4, 5].
 Adding -1 to nums[2], after which nums becomes [1, 4, 4].
 Example 2:
 Input: nums = [5,11,20,20], k = 5, numOperations = 1
 Output: 2
 Explanation:
 We can achieve a maximum frequency of two by:
 Adding 0 to nums[1].
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 109
 0 <= k <= 109
 0 <= numOperations <= nums.length
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} numOperations
 * @return {number}
 */
var maxFrequency = function(nums, k, numOperations) {
    // Sort the array in ascending order
    nums.sort((a, b) => a - b);
    
    let left = 0;
    let right = 0;
    let maxCount = 0;
    let count = 0;
    
    // Iterate through the array
    while (right < nums.length) {
        // Add the current element to the count
        count++;
        
        // Check if the current element is greater than or equal to the rightmost element plus k
        while (nums[right] - nums[left] >= k) {
            // Remove the leftmost element from the count
            count--;
            left++;
        }
        
        // Update the maximum count
        maxCount = Math.max(maxCount, count);
        
        // Move the right pointer to the next element
        right++;
    }
    
    return maxCount;
    
};