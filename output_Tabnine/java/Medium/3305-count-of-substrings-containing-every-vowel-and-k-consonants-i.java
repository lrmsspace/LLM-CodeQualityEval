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
    public int countOfSubstrings(String word, int k) {
        // Initialize variables
        int n = word.length();
        int count = 0;
        
        // Create a boolean array to keep track of vowels
        boolean[] vowels = new boolean[5];
        vowels['a'] = vowels['e'] = vowels['i'] = vowels['o'] = vowels['u'] = true;
        int consonantsCount = 0;
        int start = 0;
        int end = 0;
        // Iterate through the string
        while (end < n) {
            // Check if the current character is a consonant
            if (!vowels[word.charAt(end) - 'a']) {
                consonantsCount++;
            }
            // If the number of consonants is less than k, move the end pointer
            while (consonantsCount < k) {
                if (!vowels[word.charAt(start) - 'a']) {
                    consonantsCount--;
                }
                start++;
            }
            // If the number of consonants is equal to k, add the substring to the count
            if (consonantsCount == k) {
                count += n - end;
            }
            end++;
        }
        
        return count;
        
        
    }
}