/**https://leetcode.com/problems/count-number-of-special-subsequences/ */
//A sequence is special if it consists of a positive number of 0s, followed by a positive number of 1s, then a positive number of 2s.
//	For example, [0,1,2] and [0,0,1,1,1,2] are special.
//	In contrast, [2,1,0], [1], and [0,1,2,0] are not special.
//Given an array nums (consisting of only integers 0, 1, and 2), return the number of different subsequences that are special. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements. Two subsequences are different if the set of indices chosen are different.
// 
//Example 1:
//Input: nums = [0,1,2,2]
//Output: 3
//Explanation: The special subsequences are bolded [0,1,2,2], [0,1,2,2], and [0,1,2,2].
//Example 2:
//Input: nums = [2,2,0,0]
//Output: 0
//Explanation: There are no special subsequences in [2,2,0,0].
//Example 3:
//Input: nums = [0,1,2,0,1,2]
//Output: 7
//Explanation: The special subsequences are bolded:
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
//- [0,1,2,0,1,2]
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 2
/**
 * @param {number[]} nums
 * @return {number}
 */
var countSpecialSubsequences = function(nums) {
    const MOD = 10 ** 9 + 7;
    const dp = Array(nums.length + 1).fill(0);
    dp[0] = 1;
    const ones = Array(nums.length + 1).fill(0);
    const twos = Array(nums.length + 1).fill(0);
    for (let i = 1; i <= nums.length; i++) {
        if (nums[i - 1] === 0) {
            dp[i] = (dp[i] + dp[ones[i - 1]]) % MOD;
            ones[i] = ones[i - 1] + 1;
        } else if (nums[i - 1] === 1) {
            dp[i] = (dp[i] + dp[ones[i - 1]] + dp[twos[i - 1]]) % MOD;
            ones[i] = ones[i - 1] + 1;
            twos[i] = twos[i - 1];
        } else {
            dp[i] = (dp[i] + dp[ones[i - 1]] + dp[twos[i - 1]]) % MOD;
            ones[i] = ones[i - 1];
            twos[i] = twos[i - 1] + 1;
        }
        console.log(dp[i]);

    }
    return dp[nums.length];
    
};