/*
 You are given a 1-indexed array nums. Your task is to select a complete subset from nums where every pair of selected indices multiplied is a perfect square,. i. e. if you select ai and aj, i * j must be a perfect square.
 Return the sum of the complete subset with the maximum sum.
 Example 1:
 Input: nums = [8,7,3,5,7,2,4,9]
 Output: 16
 Explanation:
 We select elements at indices 2 and 8 and 2 * 8 is a perfect square.
 Example 2:
 Input: nums = [8,10,3,8,1,13,7,9,4]
 Output: 20
 Explanation:
 We select elements at indices 1, 4, and 9. 1 * 4, 1 * 9, 4 * 9 are perfect squares.
 Constraints:
 1 <= n == nums.length <= 104
 1 <= nums[i] <= 109
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumSum = function(nums) {
    const n = nums.length;
    const dp = Array(n + 1).fill(0);
    let maxSum = 0;
    
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= i; j++) {
            const product = nums[i - 1] * nums[j - 1];
            if (Math.sqrt(product) % 1 === 0) {
                dp[i] = Math.max(dp[i], dp[j - 1] + product);
                maxSum = Math.max(maxSum, dp[i]);
            }
        }
    }
    
    return maxSum;
    
};