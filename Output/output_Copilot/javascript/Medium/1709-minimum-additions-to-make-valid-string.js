/**https://leetcode.com/problems/minimum-additions-to-make-valid-string/ */
//Given a string word to which you can insert letters "a", "b" or "c" anywhere and any number of times, return the minimum number of letters that must be inserted so that word becomes valid.
//A string is called valid if it can be formed by concatenating the string "abc" several times.
// 
//Example 1:
//Input: word = "b"
//Output: 2
//Explanation: Insert the letter "a" right before "b", and the letter "c" right next to "b" to obtain the valid string "abc".
//Example 2:
//Input: word = "aaa"
//Output: 6
//Explanation: Insert letters "b" and "c" next to each "a" to obtain the valid string "abcabcabc".
//Example 3:
//Input: word = "abc"
//Output: 0
//Explanation: word is already valid. No modifications are needed. 
// 
//Constraints:
//	1 <= word.length <= 50
//	word consists of letters "a", "b" and "c" only. 
/**
 * @param {string} word
 * @return {number}
 */
var addMinimum = function(word) {
    let count = 0;
    let i = 0;
    while (i < word.length) {
        const expectedChar = String.fromCharCode('a'.charCodeAt(0) + (i % 3));
        if (word[i] !== expectedChar) {
            count++;
        } else {
            i++;
        }
    }
    return count + (3 - (word.length % 3)) % 3;    
};