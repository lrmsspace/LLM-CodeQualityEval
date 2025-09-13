/*
 You are given a palindromic string s.
 Return the lexicographically smallest palindromic permutation of s.
 Example 1:
 Input: s = "z"
 Output: "z"
 Explanation:
 A string of only one character is already the lexicographically smallest palindrome.
 Example 2:
 Input: s = "babab"
 Output: "abbba"
 Explanation:
 Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.
 Example 3:
 Input: s = "daccad"
 Output: "acddca"
 Explanation:
 Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.
 Constraints:
 1 <= s.length <= 105
 s consists of lowercase English letters.
 s is guaranteed to be palindromic.
*/

char* smallestPalindrome(char* s) {
    int count[26] = {0};
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int left = 0, right = len - 1;

    // Count character frequencies
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    // Form the first half of the palindrome
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            result[left++] = 'a' + i;
            count[i]--;
        }
    }

    // If there's an odd character, place it in the middle
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 == 1) {
            result[left++] = 'a' + i;
            break;
        }
    }

    // Form the second half of the palindrome
    for (int i = 25; i >= 0; i--) {
        while (count[i] > 0) {
            result[left++] = 'a' + i;
            count[i] -= 2;
        }
    }

    result[left] = '\0';
    return result;
}