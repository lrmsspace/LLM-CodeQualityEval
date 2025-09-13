/*
 You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
 Return the number of special letters in word.
 Example 1:
 Input: word = "aaAbcBC"
 Output: 3
 Explanation:
 The special characters in word are 'a', 'b', and 'c'.
 Example 2:
 Input: word = "abc"
 Output: 0
 Explanation:
 No character in word appears in uppercase.
 Example 3:
 Input: word = "abBCab"
 Output: 1
 Explanation:
 The only special character in word is 'b'.
 Constraints:
 1 <= word.length <= 50
 word consists of only lowercase and uppercase English letters.
*/

/**
 * @param {string} word
 * @return {number}
 */
var numberOfSpecialChars = function(word) {
    let count = 0;
    let seenLower = {};
    let seenUpper = {};
    for (let char of word) {
        if (char === char.toLowerCase()) {
            if (seenUpper[char.toUpperCase()]) count++;
            seenLower[char] = true;
        } else {
            if (seenLower[char.toLowerCase()]) count++;
            seenUpper[char] = true;
        }
    }
    return count;
    
};