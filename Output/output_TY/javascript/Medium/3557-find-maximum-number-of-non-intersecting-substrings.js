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
    let ans = 0;
    for (let i = 0; i < word.length; i++) {
        let count = 0;
        let j = i;
        while (j < word.length && word[j] !== 'a' && word[j] !== 'e' && word[j] !== 'i' && word[j] !== 'o' && word[j] !== 'u') {
            count++;
            j++;
        }
        if (count > 0) {
            ans++;
        }
        i = j;
    }
    return ans;
    
};