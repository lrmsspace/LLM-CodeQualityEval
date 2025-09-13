/**https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/ */
//Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
/**
 * @param {string} s
 * @return {string}
 */
var smallestSubsequence = function(s) {
    let stack = [];
    let seen = new Set();
    let lastOccurrence = {};
    for (let i = 0; i < s.length; i++) {
        lastOccurrence[s[i]] = i;
    }
    for (let i = 0; i < s.length; i++) {
        if (!seen.has(s[i])) {
            while (stack.length > 0 && s[i] < stack[stack.length - 1] && i < lastOccurrence[stack[stack.length - 1]]) {
                seen.delete(stack.pop());
            }
            stack.push(s[i]);
            seen.add(s[i]);
        }
    }
    return stack.join('');
};