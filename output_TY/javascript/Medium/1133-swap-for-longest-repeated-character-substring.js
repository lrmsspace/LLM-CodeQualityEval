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
    for(let i = 0; i < text.length; i++){
        let count = 0;
        let char = text[i];
        for(let j = i; j < text.length; j++){
            if(text[j] === char){
                count++;
            }else{
                break;
            }
        }
        let left = 0;
        let right = 0;
        if(i !== 0){
            left = 1;
            while(text[i - left] === char){
                left++;
            }
        }
        if(i !== text.length - 1){
            right = 1;
            while(text[i + right] === char){
                right++;
            }
        }
    }
    return max;
};