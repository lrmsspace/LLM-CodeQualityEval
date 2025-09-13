/**https://leetcode.com/problems/maximum-score-of-a-good-subarray/ */
//You are given an array of integers nums (0-indexed) and an integer k.
//The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.
//Return the maximum possible score of a good subarray.
// 
//Example 1:
//Input: nums = [1,4,3,7,4,5], k = 3
//Output: 15
//Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15. 
//Example 2:
//Input: nums = [5,5,4,5,4,1,1,1], k = 0
//Output: 20
//Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 2 * 104
//	0 <= k < nums.length
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumScore = function(nums, k) {
    const n = nums.length;
    let maxScore = 0;
    let minLeft = new Array(n).fill(0);
    let maxRight = new Array(n).fill(0);
    
    // calculate minLeft[i] for all i
    minLeft[0] = nums[0];
    for (let i = 1; i < n; i++) {
        minLeft[i] = Math.min(minLeft[i - 1], nums[i]);
    }
    
    // calculate maxRight[i] for all i
    maxRight[n - 1] = nums[n - 1];
    for (let i = n - 2; i >= 0; i--) {
        maxRight[i] = Math.max(maxRight[i + 1], nums[i]);
    }
    
    // calculate maxScore for all i
    for (let i = 0; i <= k; i++) {
        maxScore = Math.max(maxScore, minLeft[i] * (k - i + 1) + maxRight[i + 1] * (i + 1));
    }
    
    for (let i = k + 1; i < n; i++) {
        maxScore = Math.max(maxScore, minLeft[i] * (i - k) + maxRight[i] * (k + 1));
    }
    
    return maxScore;
    
};