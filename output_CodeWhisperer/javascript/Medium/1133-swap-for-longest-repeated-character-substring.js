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
    let max = 0;
    let count = {};
    for (let i = 0; i < text.length; i++) {
        if (!count[text[i]]) {
            count[text[i]] = 1;
        } else {
            count[text[i]]++;
        }
    }
    for (let i = 0; i < text.length; i++) {
        let char = text[i];
        let j = i;
        while (j < text.length && (text[j] === char || text[j] === text[i])) {
            j++;
        }
        let k = j + 1;
        while (k < text.length && (text[k] === char || text[k] === text[i])) {
            k++;
        }
        max = Math.max(max, Math.min(j - i + 1 + (text[k] === text[i] ? 1 : 0), count[char]));
    }
    return max;
};