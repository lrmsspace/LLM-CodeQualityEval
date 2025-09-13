/**https://leetcode.com/problems/maximum-product-of-word-lengths/ */
//Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.
// 
//Example 1:
//Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
//Output: 16
//Explanation: The two words can be "abcw", "xtfn".
//Example 2:
//Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
//Output: 4
//Explanation: The two words can be "ab", "cd".
//Example 3:
//Input: words = ["a","aa","aaa","aaaa"]
//Output: 0
//Explanation: No such pair of words.
// 
//Constraints:
//	2 <= words.length <= 1000
//	1 <= words[i].length <= 1000
//	words[i] consists only of lowercase English letters.
/**
 * @param {string[]} words
 * @return {number}
 */
var maxProduct = function(words) {
    let max = 0;
    const bitMasks = {};
    for (const word of words) {
        let mask = 0;
        for (const char of word) {
            mask |= 1 << (char.charCodeAt(0) - 97);
        }
        bitMasks[word] = mask;
        for (const key in bitMasks) {
            if (key !== word && !(mask & bitMasks[key])) {
                max = Math.max(max, word.length * key.length);
            }
        }
    }
    return max;
    
};