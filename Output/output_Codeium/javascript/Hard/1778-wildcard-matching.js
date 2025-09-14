/**https://leetcode.com/problems/wildcard-matching/ */
//Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
//	'?' Matches any single character.
//	'*' Matches any sequence of characters (including the empty sequence).
//The matching should cover the entire input string (not partial).
// 
//Example 1:
//Input: s = "aa", p = "a"
//Output: false
//Explanation: "a" does not match the entire string "aa".
//Example 2:
//Input: s = "aa", p = "*"
//Output: true
//Explanation: '*' matches any sequence.
//Example 3:
//Input: s = "cb", p = "?a"
//Output: false
//Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
// 
//Constraints:
//	0 <= s.length, p.length <= 2000
//	s contains only lowercase English letters.
//	p contains only lowercase English letters, '?' or '*'.
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    let si = 0, pi = 0, match = 0, starIdx = -1;
    while (si < s.length) {
        if (p[pi] === '?') {
            si++;
            pi++;
        } else if (s[si] === p[pi]) {
            si++;
            pi++;
            match = si;
        } else if (p[pi] === '*') {
            starIdx = pi;
            match = si;
            pi++;
        } else if (starIdx === -1) {
            return false;
        } else {
            pi = starIdx + 1;
            match++;
            si = match;
        }
    }
    while (pi < p.length && p[pi] === '*') pi++;
    return pi === p.length;
};