/**https://leetcode.com/problems/valid-anagram/ */
//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// 
//Example 1:
//Input: s = "anagram", t = "nagaram"
//Output: true
//Example 2:
//Input: s = "rat", t = "car"
//Output: false
// 
//Constraints:
//	1 <= s.length, t.length <= 5 * 104
//	s and t consist of lowercase English letters.
// 
//Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    // Create a frequency map for both strings
    let mapS = {};
    let mapT = {};
    
    for (let char of s) {
        mapS[char] = (mapS[char] || 0) + 1;
    }
    
    for (let char of t) {
        mapT[char] = (mapT[char] || 0) + 1;
    }
    
    // Compare the frequency maps
    for (let char in mapS) {
        if (!mapT[char] || mapS[char]!== mapT[char]) {
            return false;
        }
    }
    
    return true;
    
};