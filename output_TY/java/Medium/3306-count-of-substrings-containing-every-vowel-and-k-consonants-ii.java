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
        int n = word.length();
        int[] count = new int[26];
        int[] freq = new int[26];
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int index = word.charAt(i) - ' a ';
            count[index]++;
            freq[index]++;
            if (i >= k) {
                index = word.charAt(i - k) - ' a ';
                count[index]--;
                freq[index]--;
            }
            if (i >= k - 1) {
                boolean flag = true;
                for (int j = 0; j < 26; j++) {
                    if (count[j] < 1) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        return ans;
        
    }
}