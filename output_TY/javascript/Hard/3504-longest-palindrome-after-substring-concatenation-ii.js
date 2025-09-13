/*
 You are given two strings, s and t.
 You can create a new string by selecting a substring from s (possibly empty) and a substring from t (possibly empty), then concatenating them in order.
 Return the length of the longest palindrome that can be formed this way.
 Example 1:
 Input: s = "a", t = "a"
 Output: 2
 Explanation:
 Concatenating "a" from s and "a" from t results in "aa", which is a palindrome of length 2.
 Example 2:
 Input: s = "abc", t = "def"
 Output: 1
 Explanation:
 Since all characters are different, the longest palindrome is any single character, so the answer is 1.
 Example 3:
 Input: s = "b", t = "aaaa"
 Output: 4
 Explanation:
 Selecting "aaaa" from t is the longest palindrome, so the answer is 4.
 Example 4:
 Input: s = "abcde", t = "ecdba"
 Output: 5
 Explanation:
 Concatenating "abc" from s and "ba" from t results in "abcba", which is a palindrome of length 5.
 Constraints:
 1 <= s.length, t.length <= 1000
 s and t consist of lowercase English letters.
*/

/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var longestPalindrome = function(s, t) {
    let sLen = s.length;
    let tLen = t.length;
    let dp = new Array(sLen + 1).fill(0).map(() => new Array(tLen + 1).fill(0));
    for (let i = 0; i < sLen; i++) {
        for (let j = 0; j < tLen; j++) {
            if (s[i] === t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = Math.max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }  
    return sLen - dp[sLen][tLen];
};