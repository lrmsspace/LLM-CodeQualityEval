/**https://leetcode.com/problems/remove-duplicate-letters/ */
//Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
/**
 * @param {string} s
 * @return {string}
 */
var removeDuplicateLetters = function(s) {
    const stack = [];
    const seen = new Set();
    const lastIndex = new Map();

    for (let i = 0; i < s.length; i++) {
        lastIndex.set(s[i], i);
    }

    for (let i = 0; i < s.length; i++) {
        if (seen.has(s[i])) continue;

        while (stack.length && stack[stack.length - 1] > s[i] && lastIndex.get(stack[stack.length - 1]) > i) {
            seen.delete(stack.pop());
        }

        stack.push(s[i]);
        seen.add(s[i]);
    }

    return stack.join('');    
};