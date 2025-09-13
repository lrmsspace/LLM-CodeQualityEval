/*
 You are given two strings word1 and word2.
 A string x is called valid if x can be rearranged to have word2 as a prefix.
 Return the total number of valid substrings of word1.
 Note that the memory limits in this problem are smaller than usual, so you must implement a solution with a linear runtime complexity.
 Example 1:
 Input: word1 = "bcca", word2 = "abc"
 Output: 1
 Explanation:
 The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.
 Example 2:
 Input: word1 = "abcabc", word2 = "abc"
 Output: 10
 Explanation:
 All the substrings except substrings of size 1 and size 2 are valid.
 Example 3:
 Input: word1 = "abcabc", word2 = "aaabc"
 Output: 0
 Constraints:
 1 <= word1.length <= 106
 1 <= word2.length <= 104
 word1 and word2 consist only of lowercase English letters.
*/

/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var validSubstringCount = function(word1, word2) {
    const count = new Array(26).fill(0);
    for (const char of word2) {
        count[char.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    let validCount = 0;
    let left = 0;
    let right = 0;
    const n = word1.length;

    while (right < n) {
        const charIndex = word1[right].charCodeAt(0) - 'a'.charCodeAt(0);
        count[charIndex]--;

        while (count[charIndex] < 0) {
            count[word1[left].charCodeAt(0) - 'a'.charCodeAt(0)]++;
            left++;
        }

        if (right - left + 1 >= word2.length) {
            validCount += right - left + 1 - word2.length + 1;
        }
        right++;
    }

    return validCount;
        
};