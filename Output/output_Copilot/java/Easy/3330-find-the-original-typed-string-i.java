/*
 Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
 Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.
 You are given a string word, which represents the final output displayed on Alice's screen.
 Return the total number of possible original strings that Alice might have intended to type.
 Example 1:
 Input: word = "abbcccc"
 Output: 5
 Explanation:
 The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".
 Example 2:
 Input: word = "abcd"
 Output: 1
 Explanation:
 The only possible string is "abcd".
 Example 3:
 Input: word = "aaaa"
 Output: 4
 Constraints:
 1 <= word.length <= 100
 word consists only of lowercase English letters.
*/

class Solution {
    public int possibleStringCount(String word) {
        int count = 1; // Start with 1 for the original string
        int n = word.length();
        
        // Iterate through the string to find consecutive characters
        for (int i = 0; i < n; i++) {
            int j = i;
            // Count how many times the current character repeats
            while (j < n && word.charAt(j) == word.charAt(i)) {
                j++;
            }
            // If there are more than one occurrence, we can form additional strings
            if (j - i > 1) {
                count += j - i - 1; // Add the number of possible strings from this segment
            }
            i = j - 1; // Move to the next new character
        }
        
        return count;
        
    }
}