/**https://leetcode.com/problems/count-vowels-permutation/ */
//Given an integer n, your task is to count how many strings of length n can be formed under the following rules:
//	Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
//	Each vowel 'a' may only be followed by an 'e'.
//	Each vowel 'e' may only be followed by an 'a' or an 'i'.
//	Each vowel 'i' may not be followed by another 'i'.
//	Each vowel 'o' may only be followed by an 'i' or a 'u'.
//	Each vowel 'u' may only be followed by an 'a'.
//Since the answer may be too large, return it modulo 10^9 + 7.
// 
//Example 1:
//Input: n = 1
//Output: 5
//Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
//Example 2:
//Input: n = 2
//Output: 10
//Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
//Example 3: 
//Input: n = 5
//Output: 68
// 
//Constraints:
//	1 <= n <= 2 * 10^4
/**
 * @param {number} n
 * @return {number}
 */
var countVowelPermutation = function(n) {
    const MOD = 1e9 + 7;
    const dp = Array.from({ length: n + 1 }, () => Array(5).fill(0));
    for (let i = 0; i < 5; i++) dp[1][i] = 1;
    for (let i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % MOD; // a
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD; // e
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD; // i
        dp[i][3] = (dp[i - 1][2]) % MOD; // o
        dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % MOD; // u
    }
    return dp[n].reduce((a, b) => (a + b) % MOD, 0);    
};