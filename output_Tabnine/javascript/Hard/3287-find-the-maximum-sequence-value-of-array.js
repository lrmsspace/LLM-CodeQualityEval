/*
 You are given an integer array nums and a positive integer k.
 The value of a sequence seq of size 2 * x is defined as:
 (seq[0] OR seq[1] OR ... OR seq[x - 1]) XOR (seq[x] OR seq[x + 1] OR ... OR seq[2 * x - 1]).
 Return the maximum value of any subsequence of nums having size 2 * k.
 Example 1:
 Input: nums = [2,6,7], k = 1
 Output: 5
 Explanation:
 The subsequence [2, 7] has the maximum value of 2 XOR 7 = 5.
 Example 2:
 Input: nums = [4,2,5,6,7], k = 2
 Output: 2
 Explanation:
 The subsequence [4, 5, 6, 7] has the maximum value of (4 OR 5) XOR (6 OR 7) = 2.
 Constraints:
 2 <= nums.length <= 400
 1 <= nums[i] < 27
 1 <= k <= nums.length / 2
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxValue = function(nums, k) {
    // Sort the array in ascending order
    nums.sort((a, b) => a - b);
    
    // Initialize the maximum value to 0
    let max = 0;
    
    // Iterate through the array
    for (let i = 0; i <= nums.length - 2 * k; i++) {
        // Calculate the XOR value of the current subsequence
        let xorValue = nums[i] ^ nums[i + k] ^ nums[i + 2 * k];
        
        // Update the maximum value if necessary
        max = Math.max(max, xorValue);
    }
    
    // Return the maximum value
    return max;
    
};