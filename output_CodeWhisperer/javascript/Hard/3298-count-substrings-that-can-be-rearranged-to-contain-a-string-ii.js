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
    let word2Map = new Map();
    for (let i = 0; i < word2.length; i++) {
        word2Map.set(word2[i], (word2Map.get(word2[i]) || 0) + 1);
    }
    for (let i = 0; i < word1.length; i++) {
        let tempMap = new Map();
        for (let j = i; j < word1.length; j++) {
            tempMap.set(word1[j], (tempMap.get(word1[j]) || 0) + 1);
            let isValid = true;
            for (let [key, value] of word2Map) {
                if (!tempMap.has(key) || tempMap.get(key) < value) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                count++;
            }
        }
    }
    return count;    
};