/*
 You are given a string s and a pattern string p, where p contains exactly one '*' character.
 The '*' in p can be replaced with any sequence of zero or more characters.
 Return true if p can be made a substring of s, and false otherwise.
 Example 1:
 Input: s = "leetcode", p = "ee*e"
 Output: true
 Explanation:
 By replacing the '*' with "tcod", the substring "eetcode" matches the pattern.
 Example 2:
 Input: s = "car", p = "c*v"
 Output: false
 Explanation:
 There is no substring matching the pattern.
 Example 3:
 Input: s = "luck", p = "u*"
 Output: true
 Explanation:
 The substrings "u", "uc", and "uck" match the pattern.
 Constraints:
 1 <= s.length <= 50
 1 <= p.length <= 50 
 s contains only lowercase English letters.
 p contains only lowercase English letters and exactly one '*'
*/

/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var hasMatch = function(s, p) {
    // Create a 2D dp table with the same dimensions as s and p
    let dp = Array.from({ length: s.length + 1 }, () => Array(p.length + 1).fill(false));
    
    // Initialize the first row and column of the dp table
    dp[0][0] = true;
    for (let i = 1; i <= p.length; i++) {
        if (p[i - 1] === '*') {
            dp[0][i] = dp[0][i - 2];
        }
    }
    // Fill the dp table using dynamic programming
    for (let i = 1; i <= s.length; i++) {
        for (let j = 1; j <= p.length; j++) {
            if (s[i - 1] === p[j - 1] || p[j - 1] === '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] === '*') {
                dp[i][j] = dp[i][j - 2] || (s[i - 1] === p[j - 2] || p[j - 2] === '.') && dp[i - 1][j];
            }
        }
    }
    
    // Return the value in the bottom-right cell of the dp table
    return dp[s.length][p.length];
    
};