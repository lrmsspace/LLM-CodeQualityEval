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
    let n = nums.length;
    let nums2 = new Array(n + 2);
    nums2[0] = 1;
    nums2[n + 1] = 1;
    for (let i = 0; i < n; i++) {
        nums2[i + 1] = nums[i];
    }
    let dp = new Array(n + 2).fill(0).map(() => new Array(n + 2).fill(0));
    for (let i = n - 1; i >= 0; i--) {
        for (let j = i + 2; j <= n + 1; j++) {
            for (let k = i + 1; k < j; k++) {
                let sum = nums2[i] * nums2[k] * nums2[j];
                sum += dp[i][k] + dp[k][j];
                dp[i][j] = Math.max(dp[i][j], sum);
            }
        }
    }
    return dp[0][n + 1];
};