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

    const n = word.length;
    const count = new Array(1 << 10).fill(0); // 2^10 possible masks for 10 letters
    count[0] = 1; // Base case: empty string has mask 0
    let mask = 0; // Initialize mask to 0
    let result = 0; // Initialize result to 0

    for (let i = 0; i < n; i++) {
        mask ^= (1 << (word[i].charCodeAt(0) - 'a'.charCodeAt(0))); // Update mask for current character
        result += count[mask]; // Count substrings with the same mask

        // Check for substrings with one odd character
        for (let j = 0; j < 10; j++) {
            result += count[mask ^ (1 << j)]; // Count substrings with one odd character by flipping each bit
        }

        count[mask]++; // Increment the count for the current mask
    }

    return result; // Return the total count of wonderful substrings
    
};