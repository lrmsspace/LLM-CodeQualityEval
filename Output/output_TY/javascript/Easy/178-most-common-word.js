/**https://leetcode.com/problems/most-common-word/ */
//Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.
//The words in paragraph are case-insensitive and the answer should be returned in lowercase.
// 
//Example 1:
//Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
//Output: "ball"
//Explanation: 
//"hit" occurs 3 times, but it is a banned word.
//"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
//Note that words in the paragraph are not case sensitive,
//that punctuation is ignored (even if adjacent to words, such as "ball,"), 
//and that "hit" isn't the answer even though it occurs more because it is banned.
//Example 2:
//Input: paragraph = "a.", banned = []
//Output: "a"
// 
//Constraints:
//	1 <= paragraph.length <= 1000
//	paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
//	0 <= banned.length <= 100
//	1 <= banned[i].length <= 10
//	banned[i] consists of only lowercase English letters.
/**
 * @param {string} paragraph
 * @param {string[]} banned
 * @return {string}
 */
var mostCommonWord = function(paragraph, banned) {
    let bannedSet = new Set(banned);
    let words = paragraph.toLowerCase().split(/[^a-z]/);
    let map = new Map();
    for (let word of words) {
        if (word.length > 0 && !bannedSet.has(word)) {
            map.set(word, map.get(word) + 1 || 1);
        }
    }
    let max = 0;
    let result = '';
    for (let [key, value] of map) {
        if (value > max) {
            max = value;
            result = key;
        }
    }
    return result;
};