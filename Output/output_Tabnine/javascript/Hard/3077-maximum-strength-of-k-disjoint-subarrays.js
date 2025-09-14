/*
 You are given an array of integers nums with length n, and a positive odd integer k.
 Select exactly k disjoint subarrays sub1, sub2, ..., subk from nums such that the last element of subi appears before the first element of sub{i+1} for all 1 <= i <= k-1. The goal is to maximize their combined strength.
 The strength of the selected subarrays is defined as:
 strength = k * sum(sub1)- (k - 1) * sum(sub2) + (k - 2) * sum(sub3) - ... - 2 * sum(sub{k-1}) + sum(subk)
 where sum(subi) is the sum of the elements in the i-th subarray.
 Return the maximum possible strength that can be obtained from selecting exactly k disjoint subarrays from nums.
 Note that the chosen subarrays don't need to cover the entire array.
 Example 1:
 Input: nums = [1,2,3,-1,2], k = 3
 Output: 22
 Explanation:
 The best possible way to select 3 subarrays is: nums[0..2], nums[3..3], and nums[4..4]. The strength is calculated as follows:
 strength = 3 * (1 + 2 + 3) - 2 * (-1) + 2 = 22
 Example 2:
 Input: nums = [12,-2,-2,-2,-2], k = 5
 Output: 64
 Explanation:
 The only possible way to select 5 disjoint subarrays is: nums[0..0], nums[1..1], nums[2..2], nums[3..3], and nums[4..4]. The strength is calculated as follows:
 strength = 5 * 12 - 4 * (-2) + 3 * (-2) - 2 * (-2) + (-2) = 64
 Example 3:
 Input: nums = [-1,-2,-3], k = 1
 Output: -1
 Explanation:
 The best possible way to select 1 subarray is: nums[0..0]. The strength is -1.
 Constraints:
 1 <= n <= 104
 -109 <= nums[i] <= 109
 1 <= k <= n
 1 <= n * k <= 106
 k is odd.
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumStrength = function(nums, k) {
    // Sort the array in non-decreasing order
    nums.sort((a, b) => a - b);
    
    // Initialize the sum of the first k subarrays
    let sum = 0;
    for (let i = 0; i < k; i++) {
        sum += nums[i];
    }
    
    // Initialize the maximum strength
    let maxStrength = sum;
    
    // Iterate through the remaining elements to find the maximum strength
    for (let i = k; i < nums.length; i++) {
        // Remove the last element from the sum of the previous subarray
        sum -= nums[i - k];
        
        // Add the current element to the sum of the current subarray
        sum += nums[i];
        
        // Update the maximum strength
        maxStrength = Math.max(maxStrength, sum);
    }
    
    return maxStrength;
    
};