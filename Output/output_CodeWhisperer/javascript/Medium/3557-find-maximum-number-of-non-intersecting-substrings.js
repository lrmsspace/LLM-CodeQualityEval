/*
 You are given a string word.
 Return the maximum number of non-intersecting substrings of word that are at least four characters long and start and end with the same letter.
 Example 1:
 Input: word = "abcdeafdef"
 Output: 2
 Explanation:
 The two substrings are "abcdea" and "fdef".
 Example 2:
 Input: word = "bcdaaaab"
 Output: 1
 Explanation:
 The only substring is "aaaa". Note that we cannot also choose "bcdaaaab" since it intersects with the other substring.
 Constraints:
 1 <= word.length <= 2 * 105
 word consists only of lowercase English letters.
*/

/**
 * @param {string} word
 * @return {number}
 */
var maxSubstrings = function(word) {
    let count = 0;
    let start = 0;
    let end = word.length - 1;
    let current = word[start];
    while (start < end) {
        if (word[start] === word[end] && word[start] === current) {
            count++;
            start++;
            end--;
            current = word[start];
        } else {
            start++;
            current = word[start];
        }
    }
    return count;    
};