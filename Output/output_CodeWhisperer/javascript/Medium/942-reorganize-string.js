/**https://leetcode.com/problems/reorganize-string/ */
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
// 
//Example 1:
//Input: s = "aab"
//Output: "aba"
//Example 2:
//Input: s = "aaab"
//Output: ""
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @return {string}
 */
var reorganizeString = function(s) {
    let charCount = {};
    for (let char of s) {
        if (!charCount[char]) {
            charCount[char] = 1;
        } else {
            charCount[char]++;
        }
    }
    let maxCount = Math.max(...Object.values(charCount));
    if (maxCount > (s.length + 1) / 2) {
        return "";
    }
    let result = new Array(s.length);
    let index = 0;
    for (let char in charCount) {
        for (let i = 0; i < charCount[char]; i++) {
            if (index >= s.length) {
                index = 1;
            }
            result[index] = char;
            index += 2;
        }
    }
    return result.join("");
};