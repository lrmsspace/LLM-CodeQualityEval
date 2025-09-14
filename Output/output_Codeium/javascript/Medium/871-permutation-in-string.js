/**https://leetcode.com/problems/permutation-in-string/ */
//Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
//In other words, return true if one of s1's permutations is the substring of s2.
// 
//Example 1:
//Input: s1 = "ab", s2 = "eidbaooo"
//Output: true
//Explanation: s2 contains one permutation of s1 ("ba").
//Example 2:
//Input: s1 = "ab", s2 = "eidboaoo"
//Output: false
// 
//Constraints:
//	1 <= s1.length, s2.length <= 104
//	s1 and s2 consist of lowercase English letters.
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function(s1, s2) {
    if (s1.length > s2.length) return false;
    let s1_map = new Array(26).fill(0);
    let s2_map = new Array(26).fill(0);
    for (let c of s1) s1_map[c.charCodeAt() - 'a'.charCodeAt()]++;
    for (let i = 0; i < s2.length; ++i) {
        s2_map[s2.charCodeAt(i) - 'a'.charCodeAt()]++;
        if (i >= s1.length) s2_map[s2.charCodeAt(i - s1.length) - 'a'.charCodeAt()]--;
        if (s1_map.join(',') === s2_map.join(',')) return true;
    }
    return false;
};