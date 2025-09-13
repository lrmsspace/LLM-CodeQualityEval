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
    int count[26] = {0}; // Array to count occurrences of each letter
    int specialCount = 0; // Count of special letters

    // Count occurrences of each letter in both cases
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            count[word[i] - 'a'] |= 1; // Set the bit for lowercase
        } else if (word[i] >= 'A' && word[i] <= 'Z') {
            count[word[i] - 'A'] |= 2; // Set the bit for uppercase
        }
    }

    // Count special letters
    for (int i = 0; i < 26; i++) {
        if (count[i] == 3) { // Both lowercase and uppercase present
            specialCount++;
        }
    }

    return specialCount;
    
}