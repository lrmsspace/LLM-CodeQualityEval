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
        int vowelCount = 0;
        int consonantCount = 0;
        unordered_map<char, int> vowelMap;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int count = 0;
        int left = 0;

        for (int right = 0; right < word.size(); ++right) {
            char current = word[right];
            if (vowels.count(current)) {
                vowelMap[current]++;
                if (vowelMap[current] == 1) vowelCount++;
            } else {
                consonantCount++;
            }

            while (vowelCount == 5 && consonantCount > k) {
                char leftChar = word[left];
                if (vowels.count(leftChar)) {
                    vowelMap[leftChar]--;
                    if (vowelMap[leftChar] == 0) vowelCount--;
                } else {
                    consonantCount--;
                }
                left++;
            }

            if (vowelCount == 5 && consonantCount == k) {
                count++;
            }
        }

        return count;

    }
};