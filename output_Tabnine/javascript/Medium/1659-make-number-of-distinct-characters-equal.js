/**https://leetcode.com/problems/make-number-of-distinct-characters-equal/ */
//You are given two 0-indexed strings word1 and word2.
//A move consists of choosing two indices i and j such that 0 <= i < word1.length and 0 <= j < word2.length and swapping word1[i] with word2[j].
//Return true if it is possible to get the number of distinct characters in word1 and word2 to be equal with exactly one move. Return false otherwise.
// 
//Example 1:
//Input: word1 = "ac", word2 = "b"
//Output: false
//Explanation: Any pair of swaps would yield two distinct characters in the first string, and one in the second string.
//Example 2:
//Input: word1 = "abcc", word2 = "aab"
//Output: true
//Explanation: We swap index 2 of the first string with index 0 of the second string. The resulting strings are word1 = "abac" and word2 = "cab", which both have 3 distinct characters.
//Example 3:
//Input: word1 = "abcde", word2 = "fghij"
//Output: true
//Explanation: Both resulting strings will have 5 distinct characters, regardless of which indices we swap.
// 
//Constraints:
//	1 <= word1.length, word2.length <= 105
//	word1 and word2 consist of only lowercase English letters.
/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var isItPossible = function(word1, word2) {
    let count1 = new Map();
    let count2 = new Map();
    
    for (let char of word1) {
        count1.set(char, (count1.get(char) || 0) + 1);
    }
    
    for (let char of word2) {
        count2.set(char, (count2.get(char) || 0) + 1);
    }
    
    let diff = 0;
    
    for (let [char, freq] of count1.entries()) {
        if (!count2.has(char)) {
            diff += freq;
        } else if (freq > count2.get(char)) {
            diff += freq - count2.get(char);
        }
    }
    
    for (let [char, freq] of count2.entries()) {
        if (!count1.has(char)) {
            diff += freq;
        }
    }
    
    return diff <= 1;
    
};