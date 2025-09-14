/**https://leetcode.com/problems/find-all-anagrams-in-a-string/ */
//Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
// 
//Example 1:
//Input: s = "cbaebabacd", p = "abc"
//Output: [0,6]
//Explanation:
//The substring with start index = 0 is "cba", which is an anagram of "abc".
//The substring with start index = 6 is "bac", which is an anagram of "abc".
//Example 2:
//Input: s = "abab", p = "ab"
//Output: [0,1,2]
//Explanation:
//The substring with start index = 0 is "ab", which is an anagram of "ab".
//The substring with start index = 1 is "ba", which is an anagram of "ab".
//The substring with start index = 2 is "ab", which is an anagram of "ab".
// 
//Constraints:
//	1 <= s.length, p.length <= 3 * 104
//	s and p consist of lowercase English letters.
/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function(s, p) {
const result = [];
const pCount = new Array(26).fill(0);
const sCount = new Array(26).fill(0);
const aCode = 'a'.charCodeAt(0);

for (let char of p) {
    pCount[char.charCodeAt(0) - aCode]++;
}

for (let i = 0; i < s.length; i++) {
    sCount[s.charCodeAt(i) - aCode]++;
    if (i >= p.length) {
        sCount[s.charCodeAt(i - p.length) - aCode]--;
    }
    if (arraysEqual(sCount, pCount)) {
        result.push(i - p.length + 1);
    }
}

function arraysEqual(a, b) {
    for (let i = 0; i < 26; i++) {
        if (a[i] !== b[i]) return false;
    }
    return true;
}

return result;

};