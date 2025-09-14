/**https://leetcode.com/problems/longest-duplicate-substring/ */
//Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
//Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".
// 
//Example 1:
//Input: s = "banana"
//Output: "ana"
//Example 2:
//Input: s = "abcd"
//Output: ""
// 
//Constraints:
//	2 <= s.length <= 3 * 104
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @return {string}
 */
var longestDupSubstring = function(s) {
    let n = s.length;
    let dp = Array.from({length: n + 1}, () => new Array(n + 1).fill(0));
    let maxLen = 0;
    let start = 0;
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= i; j++) {
            if (s[i - 1] === s[j - 1] && dp[i - 1][j - 1] + 1 > dp[i][j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    start = j - maxLen;
                }
            }
        }
    }
    return s.substring(start, start + maxLen);
};