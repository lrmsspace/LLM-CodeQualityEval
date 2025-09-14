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
    const map = new Map();
    const stack = [];
    
    for (let char of s) {
        map.set(char, (map.get(char) || 0) + 1);
    }
    
    for (let char of s) {
        map.set(char, map.get(char) - 1);
        
        if (stack.includes(char)) continue;
        
        while (stack.length && stack[stack.length - 1] > char && map.get(stack[stack.length - 1]) > 0) {
            stack.pop();
        }
        
        stack.push(char);
    }
    
    return stack.join('');
    
};