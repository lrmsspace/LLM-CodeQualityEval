/*
 You are given a string s and an integer k.
 Determine if there exists a substring of length exactly k in s that satisfies the following conditions:
 The substring consists of only one distinct character (e.g., "aaa" or "bbb").
 If there is a character immediately before the substring, it must be different from the character in the substring.
 If there is a character immediately after the substring, it must also be different from the character in the substring.
 Return true if such a substring exists. Otherwise, return false.
 Example 1:
 Input: s = "aaabaaa", k = 3
 Output: true
 Explanation:
 The substring s[4..6] == "aaa" satisfies the conditions.
 It has a length of 3.
 All characters are the same.
 The character before "aaa" is 'b', which is different from 'a'.
 There is no character after "aaa".
 Example 2:
 Input: s = "abc", k = 2
 Output: false
 Explanation:
 There is no substring of length 2 that consists of one distinct character and satisfies the conditions.
 Constraints:
 1 <= k <= s.length <= 100
 s consists of lowercase English letters only.
*/

/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var hasSpecialSubstring = function(s, k) {
    let count = new Map();
    let prevChar = null;
    for (let i = 0; i < s.length; i++) {
        let char = s[i];
        if (count.has(char)) {
            count.set(char, count.get(char) + 1);
        } else {
            count.set(char, 1);
        }
        if (i >= k - 1) {
            let currChar = s[i - k + 1];
            if (count.get(currChar) === 1) {
                count.delete(currChar);
            } else {
                count.set(currChar, count.get(currChar) - 1);
            }
            if (prevChar && prevChar === currChar) {
                return false;
            }
            prevChar = currChar;
        }
    }
    return count.size === 1;
    
};