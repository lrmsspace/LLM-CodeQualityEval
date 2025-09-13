/*
 You are given an integer array nums and a positive integer k.
 A subsequence sub of nums with length x is called valid if it satisfies:
 (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
 Return the length of the longest valid subsequence of nums.
 Example 1:
 Input: nums = [1,2,3,4,5], k = 2
 Output: 5
 Explanation:
 The longest valid subsequence is [1, 2, 3, 4, 5].
 Example 2:
 Input: nums = [1,4,2,3,1,4], k = 3
 Output: 4
 Explanation:
 The longest valid subsequence is [1, 4, 1, 4].
 Constraints:
 2 <= nums.length <= 103
 1 <= nums[i] <= 107
 1 <= k <= 103
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumLength = function(nums, k) {
    // Create a map to store the indices of the last occurrence of each number
    const lastIndices = new Map();
    
    // Initialize variables
    let maxLength = 0;
    let currentSum = 0;
    let start = 0;  
    // Iterate through the array
    for (let end = 0; end < nums.length; end++) {
        // Update the current sum
        currentSum = (currentSum + nums[end]) % k;
        
        // If the current sum is 0, it means we have a valid subsequence
        if (currentSum === 0) {
            maxLength = Math.max(maxLength, end - start + 1);
        }
        
        // If the current sum is already in the map, update the start index
        if (lastIndices.has(currentSum)) {
            start = Math.max(start, lastIndices.get(currentSum) + 1);
        }
        
        // Update the last occurrence of the current sum
        lastIndices.set(currentSum, end);
    }
    
    return maxLength;
    
};