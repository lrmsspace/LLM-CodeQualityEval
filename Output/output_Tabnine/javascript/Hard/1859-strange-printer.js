/**https://leetcode.com/problems/strange-printer/ */
//There is a strange printer with the following two special properties:
//	The printer can only print a sequence of the same character each time.
//	At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
//Given a string s, return the minimum number of turns the printer needed to print it.
// 
//Example 1:
//Input: s = "aaabbb"
//Output: 2
//Explanation: Print "aaa" first and then print "bbb".
//Example 2:
//Input: s = "aba"
//Output: 2
//Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @return {number}
 */
var strangePrinter = function(s) {
    const dp = Array(s.length).fill(null).map(() => Array(s.length).fill(0));
    
    for (let len = 1; len <= s.length; len++) {
        for (let i = 0; i <= s.length - len; i++) {
            const j = i + len - 1;
            if (len === 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = Infinity;
                for (let k = i; k < j; k++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k + 1][j] + (s[i]!== s[k + 1]));
                }
            }
        }
    }
    
    return dp[0][s.length - 1];
    
};