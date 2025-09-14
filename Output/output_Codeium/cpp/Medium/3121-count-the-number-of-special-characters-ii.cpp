/*
 You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.
 Return the number of special letters in word.
 Example 1:
 Input: word = "aaAbcBC"
 Output: 3
 Explanation:
 The special characters are 'a', 'b', and 'c'.
 Example 2:
 Input: word = "abc"
 Output: 0
 Explanation:
 There are no special characters in word.
 Example 3:
 Input: word = "AbBCab"
 Output: 0
 Explanation:
 There are no special characters in word.
 Constraints:
 1 <= word.length <= 2 * 105
 word consists of only lowercase and uppercase English letters.
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        int seen[26] = {0};
        for (int i = 0; word[i] != '\0'; i++) {
            char c = tolower(word[i]);
            if (islower(word[i])) {
                if (seen[c - 'a'] == 1) continue;
                seen[c - 'a'] = 1;
            } else if (isupper(word[i])) {
                if (seen[c - 'A'] == 0) continue;
                seen[c - 'A'] = 2;
            }
            if (seen[c - 'a'] == 2) count++;
        }
        return count;
    }
};