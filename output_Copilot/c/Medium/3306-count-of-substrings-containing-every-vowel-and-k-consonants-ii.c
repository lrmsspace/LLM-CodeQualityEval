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
    long long count = 0;
    int vowel_count[5] = {0}; // a, e, i, o, u
    int consonant_count = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        char c = word[right];
        if (c == 'a') vowel_count[0]++;
        else if (c == 'e') vowel_count[1]++;
        else if (c == 'i') vowel_count[2]++;
        else if (c == 'o') vowel_count[3]++;
        else if (c == 'u') vowel_count[4]++;
        else consonant_count++;

        while (left <= right && (vowel_count[0] > 0 && vowel_count[1] > 0 && vowel_count[2] > 0 && 
                                 vowel_count[3] > 0 && vowel_count[4] > 0) && consonant_count > k) {
            char left_char = word[left];
            if (left_char == 'a') vowel_count[0]--;
            else if (left_char == 'e') vowel_count[1]--;
            else if (left_char == 'i') vowel_count[2]--;
            else if (left_char == 'o') vowel_count[3]--;
            else if (left_char == 'u') vowel_count[4]--;
            else consonant_count--;

            left++;
        }

        if (vowel_count[0] > 0 && vowel_count[1] > 0 && vowel_count[2] > 0 &&
            vowel_count[3] > 0 && vowel_count[4] > 0 && consonant_count == k) {
            count += left;
        }
    }

    return count;    
}