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
    const MOD = 1e9 + 7;
    const dp = new Array(s.length).fill(0).map(() => new Array(4).fill(0));
    const count = [0, 0, 0, 0];
    for (let i = 0; i < s.length; i++) {
        count[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
        dp[i][s.charCodeAt(i) - 'a'.charCodeAt(0)] = 1;
    }
    for (let len = 2; len <= s.length; len++) {
        for (let i = 0; i < s.length - len + 1; i++) {
            const j = i + len - 1;
            if (s[i] === s[j]) {
                dp[i][s.charCodeAt(j) - 'a'.charCodeAt(0)] = (dp[i + 1][s.charCodeAt(j) - 'a'.charCodeAt(0)] + dp[i][s.charCodeAt(j) - 'a'.charCodeAt(0)] * 2 + 1) % MOD;
            } else {
                dp[i][s.charCodeAt(j) - 'a'.charCodeAt(0)] = (dp[i + 1][s.charCodeAt(j) - 'a'.charCodeAt(0)] + dp[i][s.charCodeAt(j) - 'a'.charCodeAt(0)] - dp[i + 1][s.charCodeAt(j) - 'a'.charCodeAt(0)] * 2) % MOD;
            }
        }
    }
    return dp[0].reduce((a, b) => (a + b) % MOD, 0) - count[0] + 1;
};