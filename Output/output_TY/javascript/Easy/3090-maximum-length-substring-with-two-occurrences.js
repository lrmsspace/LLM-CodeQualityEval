/*
 Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
 Example 1:
 Input: s = "bcbbbcba"
 Output: 4
 Explanation:
 The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
 Example 2:
 Input: s = "aaaa"
 Output: 2
 Explanation:
 The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
 Constraints:
 2 <= s.length <= 100
 s consists only of lowercase English letters.
*/

/**
 * @param {string} s
 * @return {number}
 */
var maximumLengthSubstring = function(s) {
    let maxLength = 0;
    for (let i = 0; i < s.length; i++) {
        let count = 0;
        let seen = new Set();
        for (let j = i; j < s.length; j++) {
            if (seen.has(s[j])) {
                break;
            }
            seen.add(s[j]);
            count++;
        }
        maxLength = Math.max(maxLength, count);
    }
    return maxLength;
    
};