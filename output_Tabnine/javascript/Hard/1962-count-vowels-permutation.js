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
    const MOD = 10 ** 9 + 7;
    const dp = Array(n).fill(0).map(() => Array(5).fill(0));
    dp[0][0] = 1; // 'a' can start any permutation
    dp[0][1] = 1; // 'e' can only start with 'a'
    dp[0][2] = 1; // 'i' can only start with 'a' or 'e'
    dp[0][3] = 1; // 'o' can only start with 'i' or 'u'
    dp[0][4] = 1; // 'u' can only start with 'a'
    
    for (let i = 1; i < n; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % MOD; // 'a' can follow any vowel
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD; // 'e' can only follow 'a' or 'i'
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD; // 'i' can only follow 'e' or 'o'
        dp[i][3] = (dp[i - 1][2] + dp[i - 1][4]) % MOD; // 'o' can only follow 'i' or 'u'
        dp[i][4] = (dp[i - 1][0] + dp[i - 1][3]) % MOD; // 'u' can only follow 'a'
        // 'i' cannot follow 'i' again
        // 'o' cannot follow 'o' again
    }

    return dp[n - 1].reduce((acc, val) => acc + val, 0) % MOD;
    
};