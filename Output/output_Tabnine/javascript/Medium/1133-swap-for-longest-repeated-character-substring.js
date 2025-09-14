/**https://leetcode.com/problems/swap-for-longest-repeated-character-substring/ */
//You are given a string text. You can swap two of the characters in the text.
//Return the length of the longest substring with repeated characters.
// 
//Example 1:
//Input: text = "ababa"
//Output: 3
//Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa" with length 3.
//Example 2:
//Input: text = "aaabaaa"
//Output: 6
//Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa" with length 6.
//Example 3:
//Input: text = "aaaaa"
//Output: 5
//Explanation: No need to swap, longest repeated character substring is "aaaaa" with length is 5.
// 
//Constraints:
//	1 <= text.length <= 2 * 104
//	text consist of lowercase English characters only.
/**
 * @param {string} text
 * @return {number}
 */
var maxRepOpt1 = function(text) {
    const count = new Array(26).fill(0);
    const stack = [];
    let maxLen = 0;
    let currentLen = 0;
    let currentChar = '';
    
    for (let i = 0; i < text.length; i++) {
        const char = text[i];
        count[char.charCodeAt(0) - 97]++;
        
        if (currentChar === char) {
            currentLen++;
        } else {
            if (currentLen > 1) {
                stack.push([currentChar, currentLen]);
            }
            currentChar = char;
            currentLen = 1;
        }
    }
    
    if (currentLen > 1) {
        stack.push([currentChar, currentLen]);
    }
    
    while (stack.length > 1) {
        const [char1, len1] = stack.shift();
        const [char2, len2] = stack.shift();
        
        if (len1 === len2) {
            maxLen = Math.max(maxLen, len1 * 2);
        } else {
            maxLen = Math.max(maxLen, Math.min(len1, len2) * 2 + Math.max(len1 - Math.min(len1, len2), len2 - Math.min(len1, len2)));
        }
    }
    
    if (stack.length === 1) {
        const [char, len] = stack[0];
        maxLen = Math.max(maxLen, Math.min(count[char.charCodeAt(0) - 97], len) * 2);
    }
    
    return maxLen;
    
};