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

int numberOfSpecialChars(char* word) {
    int count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        char c = tolower(word[i]);
        bool hasUpper = false;
        bool hasLower = false;
        for (int j = 0; word[j] != '\0'; j++) {
            if (word[j] == c) hasLower = true;
            if (word[j] == toupper(c)) hasUpper = true;
            if (hasLower && hasUpper) break;
        }
        if (hasLower && hasUpper) count++;
    }
    return count;
    
}