/*
 You are given a string word and an integer k.
 A substring s of word is complete if:
 Each character in s occurs exactly k times.
 The difference between two adjacent characters is at most 2. That is, for any two adjacent characters c1 and c2 in s, the absolute difference in their positions in the alphabet is at most 2.
 Return the number of complete substrings of word.
 A substring is a non-empty contiguous sequence of characters in a string.
 Example 1:
 Input: word = "igigee", k = 2
 Output: 3
 Explanation: The complete substrings where each character appears exactly twice and the difference between adjacent characters is at most 2 are: igigee, igigee, igigee.
 Example 2:
 Input: word = "aaabbbccc", k = 3
 Output: 6
 Explanation: The complete substrings where each character appears exactly three times and the difference between adjacent characters is at most 2 are: aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc.
 Constraints:
 1 <= word.length <= 105
 word consists only of lowercase English letters.
 1 <= k <= word.length
*/

/**
 * @param {string} word
 * @param {number} k
 * @return {number}
 */
var countCompleteSubstrings = function(word, k) {
    let result = 0;
    const n = word.length;
    for (let i = 0; i < n; i++) {
        let count = 0;
        let prev = word[i].charCodeAt(0) - 'a'.charCodeAt(0);
        let diff = 0;
        let map = new Map();
        for (let j = i; j < n; j++) {
            let curr = word[j].charCodeAt(0) - 'a'.charCodeAt(0);
            if (Math.abs(curr - prev) > 2) {
                count = 0;
                diff = 0;
                map = new Map();
            }
            map.set(curr, (map.get(curr) || 0) + 1);
            if (map.get(curr) === k) {
                count++;
            }
            if (map.get(curr) === k + 1) {
                count--;
            }
            if (map.get(prev) === k) {
                count--;
            }
            if (map.get(prev) === k - 1) {
                count++;
            }
            if (map.get(curr) === 1) {
                diff++;
            }
            if (map.get(curr) === k) {
                diff--;
            }
            if (map.get(prev) === 1) {
                diff--;
            }
            if (map.get(prev) === k) {
                diff++;
            }
            prev = curr;
            if (count === 0 && diff <= 2) {
                result++;
            }
        }
    }
    return result;        
};