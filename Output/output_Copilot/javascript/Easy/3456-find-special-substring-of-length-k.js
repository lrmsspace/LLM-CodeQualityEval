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
    const n = s.length;

    // Check if k is greater than the length of the string
    if (k > n) {
        return false;
    }

    for (let i = 0; i <= n - k; i++) {
        const substring = s.substring(i, i + k);
        
        // Check if all characters in the substring are the same
        if (new Set(substring).size === 1) {
            // Check the character before and after the substring
            const beforeChar = i > 0 ? s[i - 1] : null;
            const afterChar = i + k < n ? s[i + k] : null;

            // Ensure the characters before and after are different from the substring character
            if ((beforeChar === null || beforeChar !== substring[0]) &&
                (afterChar === null || afterChar !== substring[0])) {
                return true;
            }
        }
    }

    return false;
    
};