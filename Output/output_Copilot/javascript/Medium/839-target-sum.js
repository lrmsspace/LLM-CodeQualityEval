/**https://leetcode.com/problems/target-sum/ */
//You are given an integer array nums and an integer target.
//You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
//	For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
//Return the number of different expressions that you can build, which evaluates to target.
// 
//Example 1:
//Input: nums = [1,1,1,1,1], target = 3
//Output: 5
//Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
//-1 + 1 + 1 + 1 + 1 = 3
//+1 - 1 + 1 + 1 + 1 = 3
//+1 + 1 - 1 + 1 + 1 = 3
//+1 + 1 + 1 - 1 + 1 = 3
//+1 + 1 + 1 + 1 - 1 = 3
//Example 2:
//Input: nums = [1], target = 1
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 20
//	0 <= nums[i] <= 1000
//	0 <= sum(nums[i]) <= 1000
//	-1000 <= target <= 1000
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var findTargetSumWays = function(nums, target) {
    let dp = new Array(nums.length + 1).fill(0).map(() => new Array(2001).fill(0));
    dp[0][1000] = 1; // base case: one way to achieve sum 0 with no elements

    for (let i = 1; i <= nums.length; i++) {
        for (let j = -1000; j <= 1000; j++) {
            if (dp[i - 1][j + 1000] > 0) {
                dp[i][j + nums[i - 1] + 1000] += dp[i - 1][j + 1000];
                dp[i][j - nums[i - 1] + 1000] += dp[i - 1][j + 1000];
            }
        }
    }

    return target < -1000 || target > 1000 ? 0 : dp[nums.length][target + 1000];    
};