/**https://leetcode.com/problems/number-of-wonderful-substrings/ */
//A wonderful string is a string where at most one letter appears an odd number of times.
//	For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
//Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.
//A substring is a contiguous sequence of characters in a string.
// 
//Example 1:
//Input: word = "aba"
//Output: 4
//Explanation: The four wonderful substrings are underlined below:
//- "aba" -> "a"
//- "aba" -> "b"
//- "aba" -> "a"
//- "aba" -> "aba"
//Example 2:
//Input: word = "aabb"
//Output: 9
//Explanation: The nine wonderful substrings are underlined below:
//- "aabb" -> "a"
//- "aabb" -> "aa"
//- "aabb" -> "aab"
//- "aabb" -> "aabb"
//- "aabb" -> "a"
//- "aabb" -> "abb"
//- "aabb" -> "b"
//- "aabb" -> "bb"
//- "aabb" -> "b"
//Example 3:
//Input: word = "he"
//Output: 2
//Explanation: The two wonderful substrings are underlined below:
//- "he" -> "h"
//- "he" -> "e"
// 
//Constraints:
//	1 <= word.length <= 105
//	word consists of lowercase English letters from 'a' to 'j'.
/**

 * @param {string} word

 * @return {number}

 */

var wonderfulSubstrings = function(word) {

    let count = new Array(1024).fill(0);
    count[0] = 1;
    let mask = 0, result = 0;

    for (let c of word) {
        let index = c.charCodeAt(0) - 'a'.charCodeAt(0);
        mask ^= 1 << index;
        result += count[mask];
        for (let i = 0; i < 10; i++) {
            result += count[mask ^ (1 << i)];
        }
        count[mask]++;
    }

    return result;

};