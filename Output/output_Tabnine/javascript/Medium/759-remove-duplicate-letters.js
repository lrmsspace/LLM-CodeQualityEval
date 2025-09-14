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
    let stack = [];
    let count = new Array(26).fill(0);
    let visited = new Array(26).fill(false);
    
    for (let i = 0; i < s.length; i++) {
        count[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
    }
    
    for (let i = 0; i < s.length; i++) {
        if (!visited[s.charCodeAt(i) - 'a'.charCodeAt(0)]) {
            while (stack.length && count[stack[stack.length - 1] - 'a'.charCodeAt(0)] > 0 && stack[stack.length - 1] > s[i]) {
                visited[stack.pop() - 'a'.charCodeAt(0)] = false;
            }
            stack.push(s[i]);
            visited[s.charCodeAt(i) - 'a'.charCodeAt(0)] = true;
        }
        count[s.charCodeAt(i) - 'a'.charCodeAt(0)]--;
    }
    
    return stack.join('');
    
};