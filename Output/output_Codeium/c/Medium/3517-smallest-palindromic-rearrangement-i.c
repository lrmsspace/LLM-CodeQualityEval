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
    int len = strlen(s);
    int freq[26] = {0};
    
    // Count the frequency of each character
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }
    
    // Allocate memory for the result
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int left = 0, right = len - 1;
    
    // Construct the smallest palindromic permutation
    for (int i = 0; i < 26; i++) {
        while (freq[i] > 1) {
            result[left++] = 'a' + i;
            result[right--] = 'a' + i;
            freq[i] -= 2;
        }
    }
    
    // Place the middle character if the length is odd
    for (int i = 0; i < 26; i++) {
        if (freq[i] == 1) {
            result[left] = 'a' + i;
            break;
        }
    }
    
    result[len] = '\0';
    return result;
}

