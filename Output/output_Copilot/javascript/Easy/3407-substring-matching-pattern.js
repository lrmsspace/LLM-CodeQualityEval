/*
 You are given a string s and a pattern string p, where p contains exactly one '*' character.
 The '*' in p can be replaced with any sequence of zero or more characters.
 Return true if p can be made a substring of s, and false otherwise.
 Example 1:
 Input: s = "leetcode", p = "ee*e"
 Output: true
 Explanation:
 By replacing the '*' with "tcod", the substring "eetcode" matches the pattern.
 Example 2:
 Input: s = "car", p = "c*v"
 Output: false
 Explanation:
 There is no substring matching the pattern.
 Example 3:
 Input: s = "luck", p = "u*"
 Output: true
 Explanation:
 The substrings "u", "uc", and "uck" match the pattern.
 Constraints:
 1 <= s.length <= 50
 1 <= p.length <= 50 
 s contains only lowercase English letters.
 p contains only lowercase English letters and exactly one '*'
*/

/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var hasMatch = function(s, p) {
    // Find the position of the '*' in the pattern
    const starIndex = p.indexOf('*');
    
    // If there is no '*', we can directly compare the strings
    if (starIndex === -1) {
        return s === p;
    }
    
    // Split the pattern into prefix and suffix around the '*'
    const prefix = p.slice(0, starIndex);
    const suffix = p.slice(starIndex + 1);
    
    // Check if the string starts with the prefix and ends with the suffix
    if (s.startsWith(prefix) && s.endsWith(suffix)) {
        // Check if the length of the string is sufficient to accommodate both prefix and suffix
        return s.length >= prefix.length + suffix.length;
    }
    
    return false;
    
};