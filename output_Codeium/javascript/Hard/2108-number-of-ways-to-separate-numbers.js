/**https://leetcode.com/problems/number-of-ways-to-separate-numbers/ */
//You wrote down many positive integers in a string called num. However, you realized that you forgot to add commas to seperate the different numbers. You remember that the list of integers was non-decreasing and that no integer had leading zeros.
//Return the number of possible lists of integers that you could have written down to get the string num. Since the answer may be large, return it modulo 109 + 7.
// 
//Example 1:
//Input: num = "327"
//Output: 2
//Explanation: You could have written down the numbers:
//3, 27
//327
//Example 2:
//Input: num = "094"
//Output: 0
//Explanation: No numbers can have leading zeros and all numbers must be positive.
//Example 3:
//Input: num = "0"
//Output: 0
//Explanation: No numbers can have leading zeros and all numbers must be positive.
// 
//Constraints:
//	1 <= num.length <= 3500
//	num consists of digits '0' through '9'.
/**
 * @param {string} num
 * @return {number}
 */
var numberOfCombinations = function(num) {
    let MOD = 1e9 + 7;
    let n = num.length;
    let dp = Array(n).fill(0).map(() => Array(n).fill(0));
    dp[0][0] = 1;
    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (num[j] !== '0') {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % MOD;
            }
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        }
    }
    let res = 0;
    for (let i = 1; i < n; i++) {
        res = (res + dp[n - 1][i]) % MOD;
    }
    return res;
};