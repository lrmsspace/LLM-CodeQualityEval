/**https://leetcode.com/problems/longest-string-chain/ */
//You are given an array of words where each word consists of lowercase English letters.
//wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.
//	For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
//A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
//Return the length of the longest possible word chain with words chosen from the given list of words.
// 
//Example 1:
//Input: words = ["a","b","ba","bca","bda","bdca"]
//Output: 4
//Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
//Example 2:
//Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
//Output: 5
//Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
//Example 3:
//Input: words = ["abcd","dbqca"]
//Output: 1
//Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
//["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
// 
//Constraints:
//	1 <= words.length <= 1000
//	1 <= words[i].length <= 16
//	words[i] only consists of lowercase English letters.
/**
 * @param {string[]} words
 * @return {number}
 */
var longestStrChain = function(words) {
    words.sort((a, b) => a.length - b.length);
    const dp = new Array(words.length).fill(1);
    for (let i = 1; i < words.length; i++) {
        for (let j = 0; j < i; j++) {
            if (words[i].length - words[j].length === 1 && isPredecessor(words[j], words[i])) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
    }
    return Math.max(...dp);

    function isPredecessor(s1, s2) {
        let i = 0, j = 0;
        while (i < s1.length && j < s2.length) {
            if (s1[i] !== s2[j]) {
                if (i !== j) return false;
                j++;
            } else {
                i++;
                j++;
            }
        }
        return true;
    }
};