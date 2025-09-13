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
    // Sort the array in non-decreasing order
    nums.sort((a, b) => a - b);
    
    // Initialize the frequency map
    const freqMap = new Map();
    
    // Initialize the maximum frequency
    let maxFreq = 0;
    
    // Initialize the current frequency
    let currFreq = 0;
    
    // Initialize the left pointer
    let left = 0;
    // Iterate through the array
    for (let right = 0; right < nums.length; right++) {
        // Subtract the left pointer value from the current frequency
        currFreq -= freqMap.get(nums[left]) || 0;
        
        // Add the right pointer value to the current frequency
        currFreq++;
        
        // Update the frequency map
        freqMap.set(nums[right], (freqMap.get(nums[right]) || 0) + 1);
        
        // Update the maximum frequency
        maxFreq = Math.max(maxFreq, currFreq);
        
        // If the current frequency exceeds the allowed operations, move the left pointer
        while (currFreq > numOperations) {
            currFreq -= freqMap.get(nums[left]) || 0;
            freqMap.set(nums[left], (freqMap.get(nums[left]) || 0) - 1);
            left++;
        }
    }
    
    // Return the maximum frequency
    return maxFreq;
    
};