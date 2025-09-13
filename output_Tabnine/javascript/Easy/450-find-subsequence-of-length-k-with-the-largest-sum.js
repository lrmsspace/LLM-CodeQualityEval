/**https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/ */
//You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.
//Return any such subsequence as an integer array of length k.
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
// 
//Example 1:
//Input: nums = [2,1,3,3], k = 2
//Output: [3,3]
//Explanation:
//The subsequence has the largest sum of 3 + 3 = 6.
//Example 2:
//Input: nums = [-1,-2,3,4], k = 3
//Output: [-1,3,4]
//Explanation: 
//The subsequence has the largest sum of -1 + 3 + 4 = 6.
//Example 3:
//Input: nums = [3,4,3,3], k = 2
//Output: [3,4]
//Explanation:
//The subsequence has the largest sum of 3 + 4 = 7. 
//Another possible subsequence is [4, 3].
// 
//Constraints:
//	1 <= nums.length <= 1000
//	-105 <= nums[i] <= 105
//	1 <= k <= nums.length
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSubsequence = function(nums, k) {
    // Initialize a dp array of size k+1 with zeros
    const dp = new Array(k+1).fill(0);
    
    // Iterate through the given array in reverse order
    for (let i = nums.length - 1; i >= 0; i--) {
        // Iterate through the dp array from k down to 1
        for (let j = k; j >= 1; j--) {
            // Update dp[j] by taking the maximum of dp[j] and nums[i] + dp[j-1]
            dp[j] = Math.max(dp[j], nums[i] + dp[j-1]);
        }
    }
    
    // Return the subsequence with the maximum sum
    return dp.slice(1);
    
};