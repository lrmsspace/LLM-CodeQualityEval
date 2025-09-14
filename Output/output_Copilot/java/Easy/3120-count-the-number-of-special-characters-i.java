/*
 You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
 Return the number of special letters in word.
 Example 1:
 Input: word = "aaAbcBC"
 Output: 3
 Explanation:
 The special characters in word are 'a', 'b', and 'c'.
 Example 2:
 Input: word = "abc"
 Output: 0
 Explanation:
 No character in word appears in uppercase.
 Example 3:
 Input: word = "abBCab"
 Output: 1
 Explanation:
 The only special character in word is 'b'.
 Constraints:
 1 <= word.length <= 50
 word consists of only lowercase and uppercase English letters.
*/

class Solution {
    public int numberOfSpecialChars(String word) {
        boolean[] lower = new boolean[26]; // To track lowercase letters
        boolean[] upper = new boolean[26]; // To track uppercase letters
        int specialCount = 0;

        for (char c : word.toCharArray()) {
            if (Character.isLowerCase(c)) {
                lower[c - 'a'] = true; // Mark the lowercase letter
            } else if (Character.isUpperCase(c)) {
                upper[c - 'A'] = true; // Mark the uppercase letter
            }
        }

        // Count special characters
        for (int i = 0; i < 26; i++) {
            if (lower[i] && upper[i]) {
                specialCount++; // If both lowercase and uppercase exist, count it as special
            }
        }

        return specialCount; // Return the count of special characters
        
    }
}