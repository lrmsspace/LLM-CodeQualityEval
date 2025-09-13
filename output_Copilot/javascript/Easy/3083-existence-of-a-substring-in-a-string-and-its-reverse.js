/*
 Given a string s, find any substring of length 2 which is also present in the reverse of s.
 Return true if such a substring exists, and false otherwise.
 Example 1:
 Input: s = "leetcode"
 Output: true
 Explanation: Substring "ee" is of length 2 which is also present in reverse(s) == "edocteel".
 Example 2:
 Input: s = "abcba"
 Output: true
 Explanation: All of the substrings of length 2 "ab", "bc", "cb", "ba" are also present in reverse(s) == "abcba".
 Example 3:
 Input: s = "abcd"
 Output: false
 Explanation: There is no substring of length 2 in s, which is also present in the reverse of s.
 Constraints:
 1 <= s.length <= 100
 s consists only of lowercase English letters.
*/

/**
 * @param {string} s
 * @return {boolean}
 */
var isSubstringPresent = function(s) {
    const n = s.length;
    // Check if the string has at least 2 characters
    if (n < 2) return false;

    // Create a set to store substrings of length 2
    const substrings = new Set();

    // Store all substrings of length 2 in the set
    for (let i = 0; i < n - 1; i++) {
        substrings.add(s.substring(i, i + 2));
    }

    // Check if any substring of length 2 is present in the reverse of the string
    for (let i = n - 1; i > 0; i--) {
        const sub = s.substring(i - 1, i + 1);
        if (substrings.has(sub)) {
            return true;
        }
    }

    return false;
    
};