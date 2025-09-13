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
    const s1Count = Array(26).fill(0);
    const s2Count = Array(26).fill(0);
    
    for (let i = 0; i < s1.length; i++) {
        s1Count[s1.charCodeAt(i) - 'a'.charCodeAt(0)]++;
        s2Count[s2.charCodeAt(i) - 'a'.charCodeAt(0)]++;
    }
    
    if (s1Count.toString() === s2Count.toString()) return true;
    
    for (let i = s1.length; i < s2.length; i++) {
        s2Count[s2.charCodeAt(i) - 'a'.charCodeAt(0)]++;
        s2Count[s2.charCodeAt(i - s1.length) - 'a'.charCodeAt(0)]--;
        
        if (s1Count.toString() === s2Count.toString()) return true;
    }
    
    return false;    
};