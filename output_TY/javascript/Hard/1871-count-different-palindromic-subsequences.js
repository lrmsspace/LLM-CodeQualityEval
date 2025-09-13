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
    const n = s.length;
    const dp = Array(n).fill().map(() => Array(n).fill(0));
    for (let i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for (let i = n - 2; i >= 0; i--) {
        for (let j = i + 1; j < n; j++) {
            if (s[i] === s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 4;
                let k = i + 1;
                while (k <= j - 1 && s[k] !== s[i]){
                    k++;
                }
                while (k <= j - 1 && s[j] !== s[k]){
                    j--;
                }
                if (k <= j - 1) {
                    dp[i][j] -= dp[k][j - 1];
                
                }
            }
        }
    }
    return dp[0][n - 1] % 1000000007;
};