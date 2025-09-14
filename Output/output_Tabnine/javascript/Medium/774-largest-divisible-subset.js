/**https://leetcode.com/problems/largest-divisible-subset/ */
//Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
//	answer[i] % answer[j] == 0, or
//	answer[j] % answer[i] == 0
//If there are multiple solutions, return any of them.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: [1,2]
//Explanation: [1,3] is also accepted.
//Example 2:
//Input: nums = [1,2,4,8]
//Output: [1,2,4,8]
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 2 * 109
//	All the integers in nums are unique.
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var largestDivisibleSubset = function(nums) {
    // Sort the array in ascending order
    nums.sort((a, b) => a - b);
    
    // Initialize the dp array and the length of the largest subset
    const dp = Array(nums.length).fill(1);
    let maxLength = 1;
    
    // Iterate through the array from the second element
    for (let i = 1; i < nums.length; i++) {
        // Iterate through the previous elements
        for (let j = 0; j < i; j++) {
            // If the current element is divisible by the previous element and the length of the subset ending at the previous element is greater than the current subset, update the length of the current subset
            if (nums[i] % nums[j] === 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        
        // Update the maximum length if the current subset is longer
        if (dp[i] > maxLength) {
            maxLength = dp[i];
        }
    }
    
    // Initialize an empty subset array
    const subset = [];
    
    // Iterate through the dp array from the end
    for (let i = nums.length - 1; i >= 0 && maxLength > 0; i--) {
        // If the current element is part of the largest subset and the length of the subset ending at the previous element is equal to the maximum length, add the current element to the subset
        if (dp[i] === maxLength) {
            subset.unshift(nums[i]);
            maxLength--;
        }
    }
    
    // Return the largest subset
    return subset;
    
};