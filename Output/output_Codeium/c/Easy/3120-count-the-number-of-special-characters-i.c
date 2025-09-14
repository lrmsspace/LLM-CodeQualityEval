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

int numberOfSpecialChars(char* word) {
    int count = 0;
    bool seen[26] = {false};
    
    for (int i = 0; word[i] != '\0'; i++) {
        char c = word[i];
        if (islower(c)) {
            if (!seen[c - 'a'] && strchr(word, toupper(c))) {
                seen[c - 'a'] = true;
                count++;
            }
        } else if (isupper(c)) {
            if (!seen[c - 'A'] && strchr(word, tolower(c))) {
                seen[c - 'A'] = true;
                count++;
            }
        }
    }
    
    return count;
}
