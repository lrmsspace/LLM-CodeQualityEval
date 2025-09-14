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
    // Create a frequency map for s1
    const s1Map = new Map();
    for (let char of s1) {
        s1Map.set(char, (s1Map.get(char) || 0) + 1);
    }
    
    // Create a frequency map for the current window of s2
    const windowMap = new Map();
    let left = 0;
    for (let right = 0; right < s2.length; right++) {
        const char = s2[right];
        windowMap.set(char, (windowMap.get(char) || 0) + 1);
        
        // If the current window contains a permutation of s1, shrink the window
        while (windowMap.get(char) <= s1Map.get(char)) {
            const leftChar = s2[left];
            windowMap.set(leftChar, windowMap.get(leftChar) - 1);
            left++;
        }
        
        // If the current window matches s1, return true
        if (right - left + 1 === s1.length && windowMap.every((count, char) => count === s1Map.get(char))) {
            return true;
        }
    }
    
    return false;
    
};