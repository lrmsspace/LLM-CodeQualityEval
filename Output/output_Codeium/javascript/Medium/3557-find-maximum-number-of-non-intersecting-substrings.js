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
    let n = word.length;
    let start = 0;

    while (start < n) {
        let end = start;

        // Find a valid substring starting and ending with the same letter
        while (end < n && word[start] !== word[end]) {
            end++;
        }

        // Check if the substring is long enough
        if (end - start + 1 >= 4) {
            count++;
            start = end + 1; // Move to the next potential start
        } else {
            start++;
        }
    }

    return count;
};