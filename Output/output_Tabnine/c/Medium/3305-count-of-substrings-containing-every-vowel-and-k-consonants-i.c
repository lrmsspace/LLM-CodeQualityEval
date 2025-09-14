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

int countOfSubstrings(char* word, int k) {

    int n = strlen(word);
    int count = 0;
    int vowels[5] = {0};
    
    // Count the number of vowels in the first k characters
    for (int i = 0; i < k; i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
            vowels[word[i] - 'a']++;
        }
    }   
    // If all vowels are present, increment the count   
    if (vowels[0] > 0 && vowels[1] > 0 && vowels[2] > 0 && vowels[3] > 0 && vowels[4] > 0) {
        count++;
    }
    // Iterate through the remaining characters of the word 
    for (int i = k; i < n; i++) {   
        // Decrement the count of the vowel that was at the beginning of the substring
        if (word[i - k] == 'a' || word[i - k] == 'e' || word[i - k] == 'i' || word[i - k] == 'o' || word[i - k] == 'u') {
            vowels[word[i - k] - 'a']--;
        }
        // Increment the count of the vowel that is now at the end of the substring
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
            vowels[word[i] - 'a']++;
        }
        // If all vowels are present, increment the count   
        if (vowels[0] > 0 && vowels[1] > 0 && vowels[2] > 0 && vowels[3] > 0 && vowels[4] > 0) {
            count++;
        }
    }   
    return count;   
    
}