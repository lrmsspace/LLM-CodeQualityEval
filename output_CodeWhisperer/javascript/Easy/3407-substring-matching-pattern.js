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
    let i = 0;
    let j = 0;
    while (i < s.length && j < p.length) {
        if (p[j] === '*') {
            return true;
        }
        if (s[i] === p[j] || p[j] === '?') {
            i++;
            j++;
        } else if (p[j] === '*') {
            j++;
            while (j < p.length && p[j] === '*') {
                j++;
            }
            if (j === p.length) {
                return true;
            }
            while (i < s.length) {
                if (hasMatch(s.slice(i), p.slice(j))) {
                    return true;
                }
                i++;
            }
        } else {
            return false;
        }
    }
    return i === s.length && j === p.length;  
};