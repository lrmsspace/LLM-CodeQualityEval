/*
 You are given two strings word1 and word2.
 A string x is called valid if x can be rearranged to have word2 as a prefix.
 Return the total number of valid substrings of word1.
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
 1 <= word1.length <= 105
 1 <= word2.length <= 104
 word1 and word2 consist only of lowercase English letters.
*/

/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var validSubstringCount = function(word1, word2) {
    const countWord2 = Array(26).fill(0);
    for (const char of word2) {
        countWord2[char.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    let validCount = 0;
    const n = word1.length;
    const m = word2.length;

    for (let i = 0; i <= n - m; i++) {
        const countWord1 = Array(26).fill(0);
        for (let j = i; j < n && j < i + m; j++) {
            countWord1[word1[j].charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }

        let isValid = true;
        for (let k = 0; k < 26; k++) {
            if (countWord1[k] < countWord2[k]) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            validCount++;
        }
    }

    return validCount;
        
};