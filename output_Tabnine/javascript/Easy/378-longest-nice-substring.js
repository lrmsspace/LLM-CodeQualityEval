/**https://leetcode.com/problems/longest-nice-substring/ */
//A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.
//Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.
// 
//Example 1:
//Input: s = "YazaAay"
//Output: "aAa"
//Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
//"aAa" is the longest nice substring.
//Example 2:
//Input: s = "Bb"
//Output: "Bb"
//Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
//Example 3:
//Input: s = "c"
//Output: ""
//Explanation: There are no nice substrings.
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of uppercase and lowercase English letters.
/**
 * @param {string} s
 * @return {string}
 */
var longestNiceSubstring = function(s) {
    const lower = 'abcdefghijklmnopqrstuvwxyz';
    const upper = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
    
    const map = new Map();
    for (let i = 0; i < s.length; i++) {
        map.set(s[i], map.has(s[i])? map.get(s[i]) + 1 : 1);
    }
    
    let start = 0;
    let maxLen = 0;
    let left = 0;
    let right = 0;
    
    while (right < s.length) {
        if (map.has(lower.includes(s[right])? s[right].toUpperCase() : s[right]) &&
            map.has(upper.includes(s[right])? s[right].toLowerCase() : s[right])) {
            right++;
        } else {
            while (left < right &&!map.has(lower.includes(s[left])? s[left].toUpperCase() : s[left]) &&
                 !map.has(upper.includes(s[left])? s[left].toLowerCase() : s[left])) {
                left++;
            }
            if (right - left > maxLen) {
                maxLen = right - left;
                start = left;
            }
            left++;
        }
    }
    
    return s.slice(start, start + maxLen);
    
};