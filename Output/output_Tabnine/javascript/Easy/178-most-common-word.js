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
    // Remove punctuation and convert to lowercase
    paragraph = paragraph.replace(/[^\w\s]|_/g, "").toLowerCase();
    
    // Split the paragraph into words
    let words = paragraph.split(/\s+/);
    
    // Create a frequency map
    let wordCount = {};
    
    // Iterate through the words and update the frequency map
    for (let word of words) {
        if (!banned.includes(word)) {
            wordCount[word] = (wordCount[word] || 0) + 1;
        }
    }
    
    // Find the most frequent non-banned word
    let maxCount = 0;
    let mostFrequentWord = "";
    for (let word in wordCount) {
        if (wordCount[word] > maxCount &&!banned.includes(word)) {
            maxCount = wordCount[word];
            mostFrequentWord = word;
        }
    }
    
    return mostFrequentWord;
    
};