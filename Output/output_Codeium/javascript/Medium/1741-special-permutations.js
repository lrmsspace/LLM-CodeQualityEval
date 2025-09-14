/**https://leetcode.com/problems/special-permutations/ */
//You are given a 0-indexed integer array nums containing n distinct positive integers. A permutation of nums is called special if:
//	For all indexes 0 <= i < n - 1, either nums[i] % nums[i+1] == 0 or nums[i+1] % nums[i] == 0.
//Return the total number of special permutations. As the answer could be large, return it modulo 109 + 7.
// 
//Example 1:
//Input: nums = [2,3,6]
//Output: 2
//Explanation: [3,6,2] and [2,6,3] are the two special permutations of nums.
//Example 2:
//Input: nums = [1,4,3]
//Output: 2
//Explanation: [3,1,4] and [4,1,3] are the two special permutations of nums.
// 
//Constraints:
//	2 <= nums.length <= 14
//	1 <= nums[i] <= 109
/**
 * @param {number[]} nums
 * @return {number}
 */
var specialPerm = function(nums) {
    const MOD = 1e9 + 7;
    const factorial = (n) => {
        let res = 1;
        for (let i = 1; i <= n; i++) {
            res = (res * i) % MOD;
        }
        return res;
    };
    const count = (arr) => {
        const n = arr.length;
        const dp = Array(n).fill(0).map(() => Array(n).fill(0));
        dp[0][0] = 1;
        for (let i = 1; i < n; i++) {
            for (let j = 0; j < i; j++) {
                if (arr[i] % arr[j] === 0) {
                    for (let k = 0; k <= j; k++) {
                        dp[i][k] = (dp[i][k] + dp[j][k]) % MOD;
                    }
                }
                if (arr[j] % arr[i] === 0) {
                    for (let k = j; k < i; k++) {
                        dp[i][k] = (dp[i][k] + dp[j][j]) % MOD;
                    }
                }
            }
        }
        return dp[n - 1].reduce((a, b) => (a + b) % MOD, 0);
    };
    return count(nums) * factorial(nums.length - 1) % MOD;
};