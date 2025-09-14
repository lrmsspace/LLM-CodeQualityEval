/*
 You are given a string word and a non-negative integer k.
 Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.
 Example 1:
 Input: word = "aeioqq", k = 1
 Output: 0
 Explanation:
 There is no substring with every vowel.
 Example 2:
 Input: word = "aeiou", k = 0
 Output: 1
 Explanation:
 The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".
 Example 3:
 Input: word = "ieaouqqieaouqq", k = 1
 Output: 3
 Explanation:
 The substrings with every vowel and one consonant are:
 word[0..5], which is "ieaouq".
 word[6..11], which is "qieaou".
 word[7..12], which is "ieaouq".
 Constraints:
 5 <= word.length <= 2 * 105
 word consists only of lowercase English letters.
 0 <= k <= word.length - 5
*/

/**
 * @param {string} word
 * @param {number} k
 * @return {number}
 */
var countOfSubstrings = function(word, k) {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    let vowelCount = 0;
    let consonantCount = 0;
    const vowelMap = new Map();
    let count = 0;
    let left = 0;

    for (let right = 0; right < word.length; right++) {
        const current = word[right];
        if (vowels.has(current)) {
            vowelMap.set(current, (vowelMap.get(current) || 0) + 1);
            if (vowelMap.get(current) === 1) vowelCount++;
        } else {
            consonantCount++;
        }

        while (vowelCount === 5 && consonantCount > k) {
            const leftChar = word[left];
            if (vowels.has(leftChar)) {
                vowelMap.set(leftChar, vowelMap.get(leftChar) - 1);
                if (vowelMap.get(leftChar) === 0) vowelCount--;
            } else {
                consonantCount--;
            }
            left++;
        }

        if (vowelCount === 5 && consonantCount === k) {
            count++;
        }
    }

    return count;

};