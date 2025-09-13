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
        int n = word.size();
        vector<int> lower(26, -1);
        vector<int> upper(26, -1);
        
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (c >= 'a' && c <= 'z') {
                if (lower[c - 'a'] == -1) {
                    lower[c - 'a'] = i;
                }
            } else {
                if (upper[c - 'A'] == -1) {
                    upper[c - 'A'] = i;
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] != -1 && upper[i] != -1 && lower[i] < upper[i]) {
                count++;
            }
        }
        
        return count;
       
    }
};