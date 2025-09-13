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
    // Convert paragraph to lowercase and replace punctuation with spaces
    paragraph = paragraph.toLowerCase().replace(/[!?',;.] /g, ' ');
    // Split the paragraph into words
    const words = paragraph.split(' ');
    // Create a map to count the frequency of each word
    const wordCount = {};
    for (const word of words) {
        if (word && !banned.includes(word)) {
            wordCount[word] = (wordCount[word] || 0) + 1;
        }
    }
    // Find the most common word
    let mostCommon = '';
    let maxCount = 0;
    for (const [word, count] of Object.entries(wordCount)) {
        if (count > maxCount) {
            maxCount = count;
            mostCommon = word;
        }
    }
    return mostCommon;    
};