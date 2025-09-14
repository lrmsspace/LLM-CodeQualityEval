/*
 Given a string s of length n and an integer k, determine whether it is possible to select k disjoint special substrings.
 A special substring is a substring where:
 Any character present inside the substring should not appear outside it in the string.
 The substring is not the entire string s.
 Note that all k substrings must be disjoint, meaning they cannot overlap.
 Return true if it is possible to select k such disjoint special substrings; otherwise, return false.
 Example 1:
 Input: s = "abcdbaefab", k = 2
 Output: true
 Explanation:
 We can select two disjoint special substrings: "cd" and "ef".
 "cd" contains the characters 'c' and 'd', which do not appear elsewhere in s.
 "ef" contains the characters 'e' and 'f', which do not appear elsewhere in s.
 Example 2:
 Input: s = "cdefdc", k = 3
 Output: false
 Explanation:
 There can be at most 2 disjoint special substrings: "e" and "f". Since k = 3, the output is false.
 Example 3:
 Input: s = "abeabe", k = 0
 Output: true
 Constraints:
 2 <= n == s.length <= 5 * 104
 0 <= k <= 26
 s consists only of lowercase English letters.
*/

/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var maxSubstringLength = function(s, k) {
    const n = s.length;
    const charCount = new Array(26).fill(0);
    let uniqueChars = 0;

    // Count the frequency of each character in the string
    for (let i = 0; i < n; i++) {
        const index = s.charCodeAt(i) - 'a'.charCodeAt(0);
        if (charCount[index] === 0) {
            uniqueChars++;
        }
        charCount[index]++;
    }

    // If the number of unique characters is less than k, return false
    if (uniqueChars < k) {
        return false;
    }

    // Check if we can find k disjoint special substrings
    let specialSubstrings = 0;
    for (let i = 0; i < n; i++) {
        if (charCount[s.charCodeAt(i) - 'a'.charCodeAt(0)] === 1) {
            specialSubstrings++;
            // Skip to the next character that is not part of the current special substring
            while (i < n && charCount[s.charCodeAt(i) - 'a'.charCodeAt(0)] === 1) {
                i++;
            }
        }
    }

    return specialSubstrings >= k;
        
};