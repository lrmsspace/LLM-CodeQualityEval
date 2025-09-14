/**https://leetcode.com/problems/detect-capital/ */
//We define the usage of capitals in a word to be right when one of the following cases holds:
//	All letters in this word are capitals, like "USA".
//	All letters in this word are not capitals, like "leetcode".
//	Only the first letter in this word is capital, like "Google".
//Given a string word, return true if the usage of capitals in it is right.
// 
//Example 1:
//Input: word = "USA"
//Output: true
//Example 2:
//Input: word = "FlaG"
//Output: false
// 
//Constraints:
//	1 <= word.length <= 100
//	word consists of lowercase and uppercase English letters.
/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function(word) {
    const n = word.length;
    let allUpper = true, allLower = true, firstUpper = true;
    for (let i = 0; i < n; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            allLower = false;
            if (i > 0) firstUpper = false;
        } else {
            allUpper = false;
        }
    }
    return allUpper || allLower || firstUpper;
};