/*
 You are given an integer array nums and an integer m.
 Return the maximum product of the first and last elements of any subsequence of nums of size m.
 Example 1:
 Input: nums = [-1,-9,2,3,-2,-3,1], m = 1
 Output: 81
 Explanation:
 The subsequence [-9] has the largest product of the first and last elements: -9 * -9 = 81. Therefore, the answer is 81.
 Example 2:
 Input: nums = [1,3,-5,5,6,-4], m = 3
 Output: 20
 Explanation:
 The subsequence [-5, 6, -4] has the largest product of the first and last elements.
 Example 3:
 Input: nums = [2,-1,2,-6,5,2,-5,7], m = 2
 Output: 35
 Explanation:
 The subsequence [5, 7] has the largest product of the first and last elements.
 Constraints:
 1 <= nums.length <= 105
 -105 <= nums[i] <= 105
 1 <= m <= nums.length
*/

/**
 * @param {number[]} nums
 * @param {number} m
 * @return {number}
 */
var maximumProduct = function(nums, m) {
    // Sort the array in descending order
    nums.sort((a, b) => b - a);
    
    // Initialize the maximum product as the product of the first and last elements
    let maxProduct = nums[0] * nums[1];
    
    // Iterate over the remaining elements to form subsequences of size m
    for (let i = 2; i < m; i++) {
        // Calculate the product of the first and last elements of the subsequence
        maxProduct = Math.max(maxProduct, nums[i] * nums[i - 1]);
        
        // If the product of the current subsequence is larger than the maximum product, update the maximum product
        if (maxProduct > nums[nums.length - 1] * nums[nums.length - i]) {
            maxProduct = nums[nums.length - 1] * nums[nums.length - i];
        }
    }
    
    return maxProduct;
    
};