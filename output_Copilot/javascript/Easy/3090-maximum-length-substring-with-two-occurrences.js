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
    const n = s.length;
    let maxLength = 0;
    const charCount = {};

    for (let i = 0; i < n; i++) {
        charCount[s[i]] = (charCount[s[i]] || 0) + 1;

        while (Object.values(charCount).some(count => count > 2)) {
            charCount[s[i - maxLength]]--;
            if (charCount[s[i - maxLength]] === 0) {
                delete charCount[s[i - maxLength]];
            }
            maxLength--;
        }

        maxLength++;
    }

    return maxLength;
    
};