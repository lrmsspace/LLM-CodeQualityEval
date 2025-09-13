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
    int len = strlen(word);
    int count = 0;
    int vowels[26] = {0};
    vowels['a' - 'a'] = 1;
    vowels['e' - 'a'] = 1;
    vowels['i' - 'a'] = 1;
    vowels['o' - 'a'] = 1;
    vowels['u' - 'a'] = 1;
    
    for (int i = 0; i < len; i++) {
        int v = 0;
        int c = 0;
        for (int j = i; j < len; j++) {
            if (vowels[word[j] - 'a']) {
                v++;
            } else {
                c++;
            }
            if (v >= 1 && c >= k) {
                count++;
            }
        }
    }
    return count;    
}