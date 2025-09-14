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
    // If p is empty, then s must also be empty.
    if (p === '') return s === '';
    
    // If p has a '*', then either p can be ignored or match zero or more characters.
    const firstMatch = (s!== '' && (s[0] === p[0] || p[0] === '?'));
    
    // If p has a '*', then we have two options:
    // 1. Ignore the first character of s and continue matching the rest of p with s.
    // 2. Match the first character of s with the first character of p and continue matching the rest of p with the rest of s.
    return firstMatch || (p[0] === '*' && isMatch(s, p.slice(1)));
    
};