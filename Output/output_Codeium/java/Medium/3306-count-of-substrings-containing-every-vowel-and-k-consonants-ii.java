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

class Solution {
    public long countOfSubstrings(String word, int k) {
        int[] vowels = new int[5]; // to track occurrences of 'a', 'e', 'i', 'o', 'u'
        int consonantCount = 0;
        int left = 0;
        long total = 0;
        int n = word.length();

        for (int right = 0; right < n; right++) {
            char current = word.charAt(right);
            if ("aeiou".indexOf(current) != -1) {
                vowels[current - 'a']++;
            } else {
                consonantCount++;
            }

            while (consonantCount > k) {
                char leftChar = word.charAt(left);
                if ("aeiou".indexOf(leftChar) != -1) {
                    vowels[leftChar - 'a']--;
                } else {
                    consonantCount--;
                }
                left++;
            }

            boolean allVowelsPresent = true;
            for (int count : vowels) {
                if (count == 0) {
                    allVowelsPresent = false;
                    break;
                }
            }

            if (allVowelsPresent && consonantCount == k) {
                total++;
            }
        }

        return total;

    }
}