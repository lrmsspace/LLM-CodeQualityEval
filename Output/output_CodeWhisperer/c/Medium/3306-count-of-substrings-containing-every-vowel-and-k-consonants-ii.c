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

long long countOfSubstrings(char* word, int k) {
    int n = strlen(word);
    int vowels[26] = {0};
    vowels[0] = vowels[4] = vowels[8] = vowels[14] = vowels[20] = 1;
    int consonants[26] = {0};
    for (int i = 0; i < 26; i++) {
        if (!vowels[i]) {
            consonants[i] = 1;
        }
    }
    
    long long ans = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int left = 0;
    for (int right = 0; right < n; right++) {
        if (vowels[word[right] - 'a']) {
            vowelCount++;
        } else {
            consonantCount++;
        }
        
        while (vowelCount > 0 && consonantCount > k - 1) {
            if (vowels[word[left] - 'a']) {
                vowelCount--;
            } else {
                consonantCount--;
            }
            left++;
        }
        
        if (vowelCount > 0 && consonantCount == k - 1) {
            ans += left + 1;
        }
    }
    
    vowelCount = 0;
    consonantCount = 0;
    left = 0;
    for (int right = 0; right < n; right++) {
        if (consonants[word[right] - 'a']) {
            consonantCount++;
        } else {
            vowelCount++;
        }
        
        while (consonantCount > 0 && vowelCount > k - 1) {
            if (consonants[word[left] - 'a']) {
                consonantCount--;
            } else {
                vowelCount--;
            }
            left++;
        }
        
        if (consonantCount > 0 && vowelCount == k - 1) {
            ans += left + 1;
        }
    }
    
    return ans;
}