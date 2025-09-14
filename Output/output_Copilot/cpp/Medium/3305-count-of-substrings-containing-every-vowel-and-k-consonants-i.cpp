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

class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int vowels = 0, consonants = 0;
            unordered_set<char> seen_vowels;

            for (int j = i; j < n; ++j) {
                char c = word[j];
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    seen_vowels.insert(c);
                    vowels++;
                } else {
                    consonants++;
                }

                if (seen_vowels.size() == 5 && consonants == k) {
                    count++;
                }
            }
        }

        return count;        
    }
};