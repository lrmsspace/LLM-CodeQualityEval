/*
 You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.
 Return the total number of ways to partition nums under this condition.
 Since the answer may be too large, return it modulo 109 + 7.
 Example 1:
 Input: nums = [9,4,1,3,7], k = 4
 Output: 6
 Explanation:
 There are 6 valid partitions where the difference between the maximum and minimum elements in each segment is at most k = 4:
 [[9], [4], [1], [3], [7]]
 [[9], [4], [1], [3, 7]]
 [[9], [4], [1, 3], [7]]
 [[9], [4, 1], [3], [7]]
 [[9], [4, 1], [3, 7]]
 [[9], [4, 1, 3], [7]]
 Example 2:
 Input: nums = [3,3,4], k = 0
 Output: 2
 Explanation:
 There are 2 valid partitions that satisfy the given conditions:
 [[3], [3], [4]]
 [[3, 3], [4]]
 Constraints:
 2 <= nums.length <= 5 * 104
 1 <= nums[i] <= 109
 0 <= k <= 109
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countPartitions = function(nums, k) {
    const MOD = 1000000007;
    const n = nums.length;
    const totalSum = nums.reduce((acc, num) => acc + num, 0);
    
    if (totalSum < 2 * k) {
        return 0;
    }
    
    const dp = new Array(n + 1).fill(0).map(() => new Array(k + 1).fill(0));
    
    dp[0][0] = 1;
    
    for (let i = 1; i <= n; i++) {
        for (let j = 0; j <= k; j++) {
            if (j >= nums[i - 1]) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]) % MOD;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    let result = 1;
    for (let i = 0; i <= k; i++) {
        result = (result * 2) % MOD;
    }
    
    for (let i = 0; i <= k; i++) {
        result = (result - dp[n][i] * 2 + MOD) % MOD;
    }
    
    return result;
            
};