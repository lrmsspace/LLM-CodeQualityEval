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
    const map = new Map();
    let count = 0;
    
    for (let i = 0; i < word1.length; i++) {
        const sub = word1.slice(i);
        if (sub.startsWith(word2)) {
            const prefix = sub.slice(0, word2.length);
            if (!map.has(prefix)) {
                map.set(prefix, 1);
            } else {
                map.set(prefix, map.get(prefix) + 1);
            }
        }
    }
    
    for (const [prefix, freq] of map.entries()) {
        count += freq * (freq - 1) / 2;
    }
    
    return count;   
    
};