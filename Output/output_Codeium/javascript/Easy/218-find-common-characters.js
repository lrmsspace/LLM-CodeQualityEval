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
    const map = new Map();
    for (const word of words) {
        const wMap = new Map();
        for (const c of word) {
            wMap.set(c, (wMap.get(c) || 0) + 1);
        }
        if (map.size === 0) {
            for (const [key, value] of wMap) {
                map.set(key, value);
            }
        } else {
            for (const [key, value] of map) {
                map.set(key, Math.min(value, wMap.get(key) || 0));
            }
        }
    }
    const result = [];
    for (const [key, value] of map) {
        for (let i = 0; i < value; i++) {
            result.push(key);
        }
    }
    return result;
    
};