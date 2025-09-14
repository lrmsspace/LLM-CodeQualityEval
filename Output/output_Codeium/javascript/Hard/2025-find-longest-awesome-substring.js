/**https://leetcode.com/problems/find-longest-awesome-substring/ */
//You are given a string s. An awesome substring is a non-empty substring of s such that we can make any number of swaps in order to make it a palindrome.
//Return the length of the maximum length awesome substring of s.
// 
//Example 1:
//Input: s = "3242415"
//Output: 5
//Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.
//Example 2:
//Input: s = "12345678"
//Output: 1
//Example 3:
//Input: s = "213123"
//Output: 6
//Explanation: "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists only of digits.
/**
 * @param {string} s
 * @return {number}
 */
var longestAwesome = function(s) {
    let n = s.length;
    let dp = new Array(n).fill(0).map(() => new Array(10).fill(0));
    let res = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < 10; j++) {
            if (s[i] == j + '0') {
                dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + 1;
            }
            if (i > 0) {
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
            }
            if (i > 0 && s[i] != s[i - 1]) {
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][9 - j] + 1);
            }
            res = Math.max(res, dp[i][j]);
        }
    }
    return res;
};