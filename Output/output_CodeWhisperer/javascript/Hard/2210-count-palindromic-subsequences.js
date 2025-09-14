/**https://leetcode.com/problems/count-palindromic-subsequences/ */
//Given a string of digits s, return the number of palindromic subsequences of s having length 5. Since the answer may be very large, return it modulo 109 + 7.
//Note:
//	A string is palindromic if it reads the same forward and backward.
//	A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
// 
//Example 1:
//Input: s = "103301"
//Output: 2
//Explanation: 
//There are 6 possible subsequences of length 5: "10330","10331","10301","10301","13301","03301". 
//Two of them (both equal to "10301") are palindromic.
//Example 2:
//Input: s = "0000000"
//Output: 21
//Explanation: All 21 subsequences are "00000", which is palindromic.
//Example 3:
//Input: s = "9999900000"
//Output: 2
//Explanation: The only two palindromic subsequences are "99999" and "00000".
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of digits.
/**
 * @param {string} s
 * @return {number}
 */
var countPalindromes = function(s) {
    let n = s.length;
    let mod = 1000000007;
    let res = 0;
    for (let i = 0; i < 10; i++) {
        for (let j = 0; j < 10; j++) {
            let dp = new Array(n).fill(0).map(() => new Array(10).fill(0).map(() => new Array(10).fill(0)));
            for (let k = n - 1; k >= 0; k--) {
                for (let l = 0; l < 10; l++) {
                    for (let m = 0; m < 10; m++) {
                        if (k == n - 1) {
                            if (s[k] - '0' == j && l == i && m == j) dp[k][l][m] = 1;
                            else dp[k][l][m] = 0;
                        } else {
                            if (s[k] - '0' == j && l == i && m == j) dp[k][l][m] = (dp[k + 1][i][j] + 1) % mod;
                            else if (s[k] - '0' == l && m == j) dp[k][l][m] = (dp[k + 1][i][j] + dp[k][i][m]) % mod;
                            else if (s[k] - '0' == m) dp[k][l][m] = dp[k + 1][l][m];
                            else dp[k][l][m] = dp[k + 1][l][m];
                        }
                    }
                }
            }
            res = (res + dp[0][i][j]) % mod;
        }
    }
    return res;
};