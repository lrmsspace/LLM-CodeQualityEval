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
    public int numberOfSpecialChars(String word) {
        int[] lower = new int[26];
        int[] upper = new int[26];
        int res = 0;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (c >= 'a' && c <= 'z') {
                lower[c - 'a'] = i;
            } else {
                upper[c - 'A'] = i;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (lower[i] != 0 && upper[i] != 0 && lower[i] < upper[i]) {
                res++;
            }
        }
        return res;
                
    }
}