/*
 You are given two strings, s and t.
 You can create a new string by selecting a substring from s (possibly empty) and a substring from t (possibly empty), then concatenating them in order.
 Return the length of the longest palindrome that can be formed this way.
 Example 1:
 Input: s = "a", t = "a"
 Output: 2
 Explanation:
 Concatenating "a" from s and "a" from t results in "aa", which is a palindrome of length 2.
 Example 2:
 Input: s = "abc", t = "def"
 Output: 1
 Explanation:
 Since all characters are different, the longest palindrome is any single character, so the answer is 1.
 Example 3:
 Input: s = "b", t = "aaaa"
 Output: 4
 Explanation:
 Selecting "aaaa" from t is the longest palindrome, so the answer is 4.
 Example 4:
 Input: s = "abcde", t = "ecdba"
 Output: 5
 Explanation:
 Concatenating "abc" from s and "ba" from t results in "abcba", which is a palindrome of length 5.
 Constraints:
 1 <= s.length, t.length <= 30
 s and t consist of lowercase English letters.
*/

int longestPalindrome(char* s, char* t) {
    int count[26] = {0};
    int maxLength = 0;
    int oddCount = 0;

    // Count characters in s
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
    }

    // Count characters in t
    for (int i = 0; t[i] != '\0'; i++) {
        count[t[i] - 'a']++;
    }

    // Calculate the maximum length of palindrome
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 == 0) {
            maxLength += count[i]; // Add even counts directly
        } else {
            maxLength += count[i] - 1; // Add odd counts minus one
            oddCount++; // Track odd counts
        }
    }

    // If there's at least one odd count, we can add one more character to the center of the palindrome
    if (oddCount > 0) {
        maxLength++;
    }

    return maxLength;    
}