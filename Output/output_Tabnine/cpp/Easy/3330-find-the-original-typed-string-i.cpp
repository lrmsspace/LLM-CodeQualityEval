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
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int count = 0;
        
        // Count the number of times each character appears in the word
        int charCount[26] = {0};
        for (char c : word) {
            charCount[c - 'a']++;
        }
        // Iterate through all possible combinations of characters
        for (int i = 0; i < n; i++) {
            int leftCount = i;
            int rightCount = n - i - 1;
            // Calculate the number of possible strings with the current character
            int numStrings = 1;
            for (int j = 0; j < 26; j++) {
                if (charCount[j] > 0) {
                    numStrings *= min(charCount[j], leftCount);
                    charCount[j] -= min(charCount[j], leftCount);
                }
                if (charCount[j] > 0) {
                    numStrings *= min(charCount[j], rightCount);
                    charCount[j] -= min(charCount[j], rightCount);
                }
            }
            count += numStrings;
        }
        
        return count;
        
    }
};