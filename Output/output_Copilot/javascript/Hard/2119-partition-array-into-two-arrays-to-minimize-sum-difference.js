/**https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/ */
//You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.
//Return the minimum possible absolute difference.
// 
//Example 1:
//Input: nums = [3,9,7,3]
//Output: 2
//Explanation: One optimal partition is: [3,9] and [7,3].
//The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
//Example 2:
//Input: nums = [-36,36]
//Output: 72
//Explanation: One optimal partition is: [-36] and [36].
//The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.
//Example 3:
//Input: nums = [2,-1,0,4,-2,-9]
//Output: 0
//Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
//The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.
// 
//Constraints:
//	1 <= n <= 15
//	nums.length == 2 * n
//	-107 <= nums[i] <= 107
/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumDifference = function(nums) {
    const n = nums.length / 2;
    const sum = nums.reduce((a, b) => a + b, 0);
    const halfSum = sum / 2;
    const dp = Array.from({ length: n + 1 }, () => new Set());
    dp[0].add(0);
    
    for (let i = 0; i < n; i++) {
        const nextDp = Array.from({ length: n + 1 }, () => new Set());
        for (let j = 0; j <= i; j++) {
            for (const s of dp[j]) {
                nextDp[j].add(s);
                nextDp[j + 1].add(s + nums[i]);
            }
        }
        dp.splice(0, n + 1, ...nextDp);
    }
    
    let minDiff = Infinity;
    for (const s of dp[n]) {
        minDiff = Math.min(minDiff, Math.abs(sum - 2 * s));
    }
    
    return minDiff;    
};