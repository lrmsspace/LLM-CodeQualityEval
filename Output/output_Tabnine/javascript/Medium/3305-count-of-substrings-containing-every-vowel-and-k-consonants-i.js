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
    // Initialize count and vowel count
    let count = 0;
    let vowelCount = 0;
    
    // Iterate through the word
    for (let i = 0; i < word.length; i++) {
        // Check if the current character is a vowel
        if (word[i] === 'a' || word[i] === 'e' || word[i] === 'i' || word[i] === 'o' || word[i] === 'u') {
            // Update the vowel count
            vowelCount++;
        }
        
        // Check if the vowel count is equal to the required k
        if (vowelCount === k) {
            // Count the substring
            count += word.length - i;
        }
    }
    
    return count;   
    
};