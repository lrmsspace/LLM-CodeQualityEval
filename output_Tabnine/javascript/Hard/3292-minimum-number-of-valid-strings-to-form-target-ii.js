/*
 You are given an array of strings words and a string target.
 A string x is called valid if x is a prefix of any string in words.
 Return the minimum number of valid strings that can be concatenated to form target. If it is not possible to form target, return -1.
 Example 1:
 Input: words = ["abc","aaaaa","bcdef"], target = "aabcdabc"
 Output: 3
 Explanation:
 The target string can be formed by concatenating:
 Prefix of length 2 of words[1], i.e. "aa".
 Prefix of length 3 of words[2], i.e. "bcd".
 Prefix of length 3 of words[0], i.e. "abc".
 Example 2:
 Input: words = ["abababab","ab"], target = "ababaababa"
 Output: 2
 Explanation:
 The target string can be formed by concatenating:
 Prefix of length 5 of words[0], i.e. "ababa".
 Prefix of length 5 of words[0], i.e. "ababa".
 Example 3:
 Input: words = ["abcdef"], target = "xyz"
 Output: -1
 Constraints:
 1 <= words.length <= 100
 1 <= words[i].length <= 5 * 104
 The input is generated such that sum(words[i].length) <= 105.
 words[i] consists only of lowercase English letters.
 1 <= target.length <= 5 * 104
 target consists only of lowercase English letters.
*/

/**
 * @param {string[]} words
 * @param {string} target
 * @return {number}
 */
var minValidStrings = function(words, target) {
    const prefixMap = new Map();
    for (const word of words) {
        let prefix = '';
        for (let i = 0; i < word.length; i++) {
            prefix += word[i];
            if (prefixMap.has(prefix)) {
                prefixMap.get(prefix).push(word);
            } else {
                prefixMap.set(prefix, [word]);
            }
        }
    }
    
    let targetLength = target.length;
    let minCount = Infinity;
    
    for (let i = 0; i <= targetLength; i++) {
        const prefix = target.substr(0, i);
        if (prefixMap.has(prefix)) {
            const wordsForPrefix = prefixMap.get(prefix);
            minCount = Math.min(minCount, wordsForPrefix.length);
        } else {
            break;
        }
    }
    return minCount === Infinity? -1 : minCount;
    
};