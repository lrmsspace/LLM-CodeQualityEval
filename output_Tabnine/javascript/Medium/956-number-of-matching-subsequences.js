/**https://leetcode.com/problems/number-of-matching-subsequences/ */
//Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
//A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
//	For example, "ace" is a subsequence of "abcde".
// 
//Example 1:
//Input: s = "abcde", words = ["a","bb","acd","ace"]
//Output: 3
//Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
//Example 2:
//Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
//Output: 2
// 
//Constraints:
//	1 <= s.length <= 5 * 104
//	1 <= words.length <= 5000
//	1 <= words[i].length <= 50
//	s and words[i] consist of only lowercase English letters.
/**
 * @param {string} s
 * @param {string[]} words
 * @return {number}
 */
var numMatchingSubseq = function(s, words) {
    const count = new Array(s.length + 1).fill(0);
    for (let i = 0; i < words.length; i++) {
        const word = words[i];
        const last = new Array(26).fill(0);
        let match = true;
        for (let j = 0; j < word.length; j++) {
            const index = word.charCodeAt(j) - 'a'.charCodeAt(0);
            if (!last[index]) {
                match = false;
                break;
            }
            last[index]--;
        }
        if (match) {
            count[word.length]++;
        }
    }
    
    let result = 0;
    for (let i = 1; i <= s.length; i++) {
        result += count[i];
    }
    return result;
    
};