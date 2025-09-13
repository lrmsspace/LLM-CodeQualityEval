/**https://leetcode.com/problems/keyboard-row/ */
//Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
//Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.
//In the American keyboard:
//	the first row consists of the characters "qwertyuiop",
//	the second row consists of the characters "asdfghjkl", and
//	the third row consists of the characters "zxcvbnm".
// 
//Example 1:
//Input: words = ["Hello","Alaska","Dad","Peace"]
//Output: ["Alaska","Dad"]
//Explanation:
//Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.
//Example 2:
//Input: words = ["omk"]
//Output: []
//Example 3:
//Input: words = ["adsdf","sfd"]
//Output: ["adsdf","sfd"]
// 
//Constraints:
//	1 <= words.length <= 20
//	1 <= words[i].length <= 100
//	words[i] consists of English letters (both lowercase and uppercase). 
/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(words) {
    let row1 = "qwertyuiop";
    let row2 = "asdfghjkl";
    let row3 = "zxcvbnm";
    let result = [];
    for (let i = 0; i < words.length; i++) {
        let word = words[i].toLowerCase();
        let row = 0;
        if (row1.indexOf(word[0]) !== -1) {
            row = 1;
        } else if (row2.indexOf(word[0]) !== -1) {
            row = 2;
        } else if (row3.indexOf(word[0]) !== -1) {
            row = 3;
        }
        let isSameRow = true;
        for (let j = 1; j < word.length; j++) {
            if (row === 1 && row1.indexOf(word[j]) === -1) {
                isSameRow = false;
                break;
            } else if (row === 2 && row2.indexOf(word[j]) === -1) {
                isSameRow = false;
                break;
            } else if (row === 3 && row3.indexOf(word[j]) === -1) {
                isSameRow = false;
                break;
            }
        }
        if (isSameRow) {
            result.push(words[i]);
        }
    }
    return result;
};