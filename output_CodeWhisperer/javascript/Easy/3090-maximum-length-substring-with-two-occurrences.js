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
    let max = 0;
    let count = {};
    let left = 0;
    for (let right = 0; right < s.length; right++) {
        count[s[right]] = (count[s[right]] || 0) + 1;
        while (count[s[right]] > 2) {
            count[s[left]]--;
            left++;
        }
        max = Math.max(max, right - left + 1);
    }
    return max;    
};