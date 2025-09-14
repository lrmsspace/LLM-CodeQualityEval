/**https://leetcode.com/problems/burst-balloons/ */
//You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
//If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
//Return the maximum coins you can collect by bursting the balloons wisely.
// 
//Example 1:
//Input: nums = [3,1,5,8]
//Output: 167
//Explanation:
//nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
//coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
//Example 2:
//Input: nums = [1,5]
//Output: 10
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 300
//	0 <= nums[i] <= 100
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxCoins = function(nums) {
    const n = nums.length;
    const dp = Array.from({ length: n }, () => Array.from({ length: n }, () => 0));
    const prefix = Array.from({ length: n + 1 }, (_, i) => i === 0? 1 : nums[i - 1]);
    const suffix = Array.from({ length: n + 1 }, (_, i) => i === n? 1 : nums[i]);
    
    for (let len = 2; len <= n; len++) {
        for (let i = 0; i <= n - len; i++) {
            const j = i + len - 1;
            for (let k = i; k <= j; k++) {
                dp[i][j] = Math.max(dp[i][j], prefix[i] * nums[k] * suffix[j] + dp[i][k - 1] + dp[k + 1][j]);
            }
        }
    }
    
    return dp[0][n - 1];
    
};