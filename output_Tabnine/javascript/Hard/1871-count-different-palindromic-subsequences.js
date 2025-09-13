/**https://leetcode.com/problems/count-different-palindromic-subsequences/ */
//Given a string s, return the number of different non-empty palindromic subsequences in s. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence of a string is obtained by deleting zero or more characters from the string.
//A sequence is palindromic if it is equal to the sequence reversed.
//Two sequences a1, a2, ... and b1, b2, ... are different if there is some i for which ai != bi.
// 
//Example 1:
//Input: s = "bccb"
//Output: 6
//Explanation: The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
//Note that 'bcb' is counted only once, even though it occurs twice.
//Example 2:
//Input: s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
//Output: 104860361
//Explanation: There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 109 + 7.
// 
//Constraints:
//	1 <= s.length <= 1000
//	s[i] is either 'a', 'b', 'c', or 'd'.
/**
 * @param {string} s
 * @return {number}
 */
var countPalindromicSubsequences = function(s) {
    const MOD = 10 ** 9 + 7;
    const n = s.length;
    const dp = Array.from({ length: n + 1 }, () => Array.from({ length: 26 }, () => Array(n + 1).fill(0)));
    
    for (let i = n - 1; i >= 0; i--) {
        for (let j = 0; j < 26; j++) {
            for (let k = i + 1; k <= n; k++) {
                if (s[i] === String.fromCharCode(j + 97)) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i + 1][j][k]) % MOD;
                } else {
                    dp[i][j][k] = (dp[i][j][k] + dp[i + 1][j][k] + dp[i][j][k + 1] - dp[i + 1][j][k + 1]) % MOD;
                }
            }
        }
    }
    
    let result = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < 26; j++) {
            result = (result + dp[0][j][i + 1]) % MOD;
        }
    }
    
    return result;
    
};