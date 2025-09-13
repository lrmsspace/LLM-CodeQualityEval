/**https://leetcode.com/problems/regular-expression-matching/ */
//Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
//	'.' Matches any single character.​​​​
//	'*' Matches zero or more of the preceding element.
//The matching should cover the entire input string (not partial).
// 
//Example 1:
//Input: s = "aa", p = "a"
//Output: false
//Explanation: "a" does not match the entire string "aa".
//Example 2:
//Input: s = "aa", p = "a*"
//Output: true
//Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
//Example 3:
//Input: s = "ab", p = ".*"
//Output: true
//Explanation: ".*" means "zero or more (*) of any character (.)".
// 
//Constraints:
//	1 <= s.length <= 20
//	1 <= p.length <= 20
//	s contains only lowercase English letters.
//	p contains only lowercase English letters, '.', and '*'.
//	It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    if(p.length === 0) return s.length === 0;
    
    const dp = Array(s.length + 1).fill(false).map(() => Array(p.length + 1).fill(false));
    dp[0][0] = true;
    
    for(let i = 0; i <= s.length; i++) {
        for(let j = 1; j <= p.length; j++) {
            const matchChar = p[j - 1]!== '*';
            if(matchChar && (s[i - 1] === p[j - 1] || p[j - 1] === '.')) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if(p[j - 1] === '*') {
                dp[i][j] = dp[i][j - 2] || (matchChar && (s[i - 1] === p[j - 2] || p[j - 2] === '.')) && dp[i - 1][j];
            }
        }
    }
    
    return dp[s.length][p.length];
    
};