/**https://leetcode.com/problems/find-common-characters/ */
//Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
// 
//Example 1:
//Input: words = ["bella","label","roller"]
//Output: ["e","l","l"]
//Example 2:
//Input: words = ["cool","lock","cook"]
//Output: ["c","o"]
// 
//Constraints:
//	1 <= words.length <= 100
//	1 <= words[i].length <= 100
//	words[i] consists of lowercase English letters.
/**
 * @param {string[]} words
 * @return {string[]}
 */
var commonChars = function(words) {
    let result = new Array(26).fill(Infinity);
    
    for (let word of words) {
        let count = new Array(26).fill(0);
        
        for (let char of word) {
            count[char.charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }
        
        for (let i = 0; i < 26; i++) {
            result[i] = Math.min(result[i], count[i]);
        }
    }
    
    return result.map((_, index) => String.fromCharCode(index + 'a'.charCodeAt(0))).filter(char => result[char.charCodeAt(0) - 'a'.charCodeAt(0)] > 0);
    
};