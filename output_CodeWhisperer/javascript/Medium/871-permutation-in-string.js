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
    let s1Map = new Array(26).fill(0);
    let s2Map = new Array(26).fill(0);
    for (let i = 0; i < s1.length; i++) {
        s1Map[s1.charCodeAt(i) - 97]++;
    }
    for (let i = 0; i < s2.length; i++) {
        s2Map[s2.charCodeAt(i) - 97]++;
        if (i >= s1.length) {
            s2Map[s2.charCodeAt(i - s1.length) - 97]--;
        }
        if (s1Map.join('') == s2Map.join('')) {
            return true;
        }
    }
    return false;
};