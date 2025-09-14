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
    let n = text.length;
    let count = new Array(26).fill(0);
    let left = 0;
    let right = 0;
    let maxCount = 0;
    let maxLength = 0;

    while (right < n) {
        count[text[right].charCodeAt() - 'a'.charCodeAt()]++;
        maxCount = Math.max(maxCount, count[text[right].charCodeAt() - 'a'.charCodeAt()]);
        right++;

        while (right - left - maxCount > 1) {
            count[text[left].charCodeAt() - 'a'.charCodeAt()]--;
            left++;
        }

        maxLength = Math.max(maxLength, right - left);
    }

    return Math.min(maxLength, n);    
};