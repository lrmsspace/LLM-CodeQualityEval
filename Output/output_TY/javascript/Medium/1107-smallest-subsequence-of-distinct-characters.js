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
    let lastIndex = {};
    for(let i=0;i<s.length;i++){
        lastIndex[s[i]] = i;
    }
    for(let i=0;i<s.length;i++){
        if(stack.indexOf(s[i])!==-1){
            continue;
        }
        while(stack.length>0 && stack[stack.length-1]>s[i] && lastIndex[stack[stack.length-1]]>i){
            stack.pop();
        }
        stack.push(s[i]);
    }
    return stack.join("");
 
};