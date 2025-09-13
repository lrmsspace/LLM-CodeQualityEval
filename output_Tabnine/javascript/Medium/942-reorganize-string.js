/**https://leetcode.com/problems/reorganize-string/ */
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
// 
//Example 1:
//Input: s = "aab"
//Output: "aba"
//Example 2:
//Input: s = "aaab"
//Output: ""
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @return {string}
 */
var reorganizeString = function(s) {
    // Create a frequency map to count the occurrences of each character
    let count = {};
    for (let char of s) {
        count[char] = (count[char] || 0) + 1;
    }
    
    // Sort the characters by their frequency in descending order
    let sortedChars = Object.keys(count).sort((a, b) => count[b] - count[a]);
    
    // Initialize the result string with the most frequent character
    let result = sortedChars[0];
    
    // Try to form pairs of characters that are not the same
    for (let i = 1; i < sortedChars.length; i++) {
        let char = sortedChars[i];
        
        // Try to find a character that can be placed next to the current character in the result string
        for (let j = 0; j < result.length; j++) {
            if (result[j] === char || result[j + 1] === char) {
                continue;
            }
            
            // If a suitable character is found, add it to the result string
            result = result.slice(0, j + 1) + char + result.slice(j + 1);
            break;
        }
        
        // If no suitable character is found, return an empty string
        if (result.length === s.length) {
            return "";
        }
    }
    
    return result;
    
};