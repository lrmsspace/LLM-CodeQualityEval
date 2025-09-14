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
    let count = 0;
    let letters = {};
    for (let i = 0; i < word2.length; i++) {
        if (!letters[word2[i]]) {
            letters[word2[i]] = 1;
        } else {
            letters[word2[i]]++;
        }
    }
    for (let i = 0; i < word1.length - word2.length + 1; i++) {
        let tempLetters = {};
        for (let j = 0; j < word2.length; j++) {
            if (!tempLetters[word1[i + j]]) {
                tempLetters[word1[i + j]] = 1;
            } else {
                tempLetters[word1[i + j]]++;
            }
        }
        let valid = true;
        for (let key in letters) {
            if (!tempLetters[key] || tempLetters[key] < letters[key]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            count++;
        }
    }
    return count;
};