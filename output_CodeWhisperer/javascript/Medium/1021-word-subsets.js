/**https://leetcode.com/problems/word-subsets/ */
//You are given two string arrays words1 and words2.
//A string b is a subset of string a if every letter in b occurs in a including multiplicity.
//	For example, "wrr" is a subset of "warrior" but is not a subset of "world".
//A string a from words1 is universal if for every string b in words2, b is a subset of a.
//Return an array of all the universal strings in words1. You may return the answer in any order.
// 
//Example 1:
//Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
//Output: ["facebook","google","leetcode"]
//Example 2:
//Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
//Output: ["apple","google","leetcode"]
// 
//Constraints:
//	1 <= words1.length, words2.length <= 104
//	1 <= words1[i].length, words2[i].length <= 10
//	words1[i] and words2[i] consist only of lowercase English letters.
//	All the strings of words1 are unique.
/**
 * @param {string[]} words1
 * @param {string[]} words2
 * @return {string[]}
 */
var wordSubsets = function(words1, words2) {
    let res = [];
    let maxCount = new Array(26).fill(0);
    for (let word of words2) {
        let count = new Array(26).fill(0);
        for (let c of word) {
            count[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }
        for (let i = 0; i < 26; i++) {
            maxCount[i] = Math.max(maxCount[i], count[i]);
        }
    }
    for (let word of words1) {
        let count = new Array(26).fill(0);
        for (let c of word) {
            count[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }
        let i = 0;
        while (i < 26) {
            if (count[i] < maxCount[i]) {
                break;
            }
            i++;
        }
        if (i == 26) res.push(word);
    }
    return res;
};