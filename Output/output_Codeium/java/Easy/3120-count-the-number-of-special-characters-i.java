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
        int count = 0;
        boolean[] seen = new boolean[26];
        
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (Character.isLowerCase(c)) {
                if (!seen[c - 'a'] && word.indexOf(Character.toUpperCase(c)) != -1) {
                    seen[c - 'a'] = true;
                    count++;
                }
            } else if (Character.isUpperCase(c)) {
                if (!seen[c - 'A'] && word.indexOf(Character.toLowerCase(c)) != -1) {
                    seen[c - 'A'] = true;
                    count++;
                }
            }
        }
        
        return count;

    }
}