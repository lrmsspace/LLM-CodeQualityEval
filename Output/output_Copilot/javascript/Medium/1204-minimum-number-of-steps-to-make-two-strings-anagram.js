/**https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/ */
//You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.
//Return the minimum number of steps to make t an anagram of s.
//An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.
// 
//Example 1:
//Input: s = "bab", t = "aba"
//Output: 1
//Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
//Example 2:
//Input: s = "leetcode", t = "practice"
//Output: 5
//Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
//Example 3:
//Input: s = "anagram", t = "mangaar"
//Output: 0
//Explanation: "anagram" and "mangaar" are anagrams. 
// 
//Constraints:
//	1 <= s.length <= 5 * 104
//	s.length == t.length
//	s and t consist of lowercase English letters only.
/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var minSteps = function(s, t) {
    let count = 0;
    const sCount = Array(26).fill(0);
    const tCount = Array(26).fill(0);
    
    for (let char of s) {
        sCount[char.charCodeAt() - 'a'.charCodeAt()]++;
    }
    
    for (let char of t) {
        tCount[char.charCodeAt() - 'a'.charCodeAt()]++;
    }
    
    for (let i = 0; i < 26; i++) {
        count += Math.abs(sCount[i] - tCount[i]);
    }
    
    return count / 2;    
};