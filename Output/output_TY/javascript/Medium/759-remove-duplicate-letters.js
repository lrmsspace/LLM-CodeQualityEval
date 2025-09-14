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
    let map = new Map();
    for(let i=0;i<s.length;i++){
        map.set(s[i],i);
    }
    for(let i=0;i<s.length;i++){
        if(stack.indexOf(s[i])===-1){
            while(stack.length>0 && stack[stack.length-1]>s[i] && map.get(stack[stack.length-1])>i){
                stack.pop();
            }
            stack.push(s[i]);
        }
    }
    return stack.join("");

};