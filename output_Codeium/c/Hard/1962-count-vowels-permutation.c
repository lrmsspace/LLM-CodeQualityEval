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
int countVowelPermutation(int n) {
    int dp[5][n+1];
    int M = 1e9 + 7;
    memset(dp, 0, sizeof(dp));
    dp[0][1] = dp[1][1] = dp[2][1] = dp[3][1] = dp[4][1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[0][i] = (dp[1][i-1] + dp[2][i-1] + dp[4][i-1]) % M;
        dp[1][i] = (dp[0][i-1] + dp[2][i-1]) % M;
        dp[2][i] = (dp[1][i-1] + dp[3][i-1]) % M;
        dp[3][i] = dp[2][i-1];
        dp[4][i] = (dp[2][i-1] + dp[3][i-1]) % M;
    }
    return (dp[0][n] + dp[1][n] + dp[2][n] + dp[3][n] + dp[4][n]) % M;
}