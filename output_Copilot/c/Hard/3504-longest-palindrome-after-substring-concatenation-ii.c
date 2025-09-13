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
 1 <= s.length, t.length <= 1000
 s and t consist of lowercase English letters.
*/

int longestPalindrome(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    int maxLength = 0;

    // Check all combinations of substrings from s and t
    for (int i = 0; i < sLen; i++) {
        for (int j = 0; j < tLen; j++) {
            // Create a new string by concatenating substrings
            char combined[2001]; // Max length is 1000 + 1000
            int k = 0;

            // Add substring from s
            for (int x = i; x < sLen; x++) {
                combined[k++] = s[x];
            }

            // Add substring from t
            for (int y = j; y < tLen; y++) {
                combined[k++] = t[y];
            }
            combined[k] = '\0';

            // Check if the combined string is a palindrome
            int left = 0, right = k - 1;
            while (left < right) {
                if (combined[left] != combined[right]) {
                    break;
                }
                left++;
                right--;
            }

            if (left >= right) {
                maxLength = fmax(maxLength, k);
            }
        }
    }

    return maxLength;
    
}