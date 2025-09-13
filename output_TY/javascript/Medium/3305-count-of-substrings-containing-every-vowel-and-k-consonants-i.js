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
 5 <= word.length <= 250
 word consists only of lowercase English letters.
 0 <= k <= word.length - 5
*/

/**
 * @param {string} word
 * @param {number} k
 * @return {number}
 */
var countOfSubstrings = function(word, k) {
    let count = 0;
    for (let i = 0; i < word.length - k + 1; i++) {
        let sub = word.substring(i, i + k);
        let vowelCount = 0;
        let consonantCount = 0;
        for (let j = 0; j < sub.length; j++) {
            if (sub[j] === 'a' || sub[j] === 'e' || sub[j] === 'i' || sub[j] === 'o' || sub[j] === 'u') {
                vowelCount++;
            } else {
                consonantCount++;
            }
        }
        if (vowelCount >= k) {
            return sub[k - 1];
        } else {
            let index = k - vowelCount - 1;
            let consonant = 'b';
            while (index > 0) {
                consonant = String.fromCharCode(consonant.charCodeAt(0) + 1);
                index--;
            }
            return consonant;
        }
    }
    return s.replace(vowelRegex, replaceVowel);
    
};