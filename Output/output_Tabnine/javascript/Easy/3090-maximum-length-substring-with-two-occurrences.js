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
    const charCount = {};
    let maxLen = 0;
    let start = 0;
    
    for (let end = 0; end < s.length; end++) {
        const char = s[end];
        
        if (charCount[char] === 2) {
            while (s[start]!== char) {
                charCount[s[start]]--;
                start++;
            }
            start++;
        }
        
        charCount[char]++;
        maxLen = Math.max(maxLen, end - start + 1);
    }
    
    return maxLen;
    
};