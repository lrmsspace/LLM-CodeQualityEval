/*
 You are given a palindromic string s and an integer k.
 Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.
 Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.
 Example 1:
 Input: s = "abba", k = 2
 Output: "baab"
 Explanation:
 The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
 Lexicographically, "abba" comes before "baab". Since k = 2, the output is "baab".
 Example 2:
 Input: s = "aa", k = 2
 Output: ""
 Explanation:
 There is only one palindromic rearrangement: "aa".
 The output is an empty string since k = 2 exceeds the number of possible rearrangements.
 Example 3:
 Input: s = "bacab", k = 1
 Output: "abcba"
 Explanation:
 The two distinct palindromic rearrangements of "bacab" are "abcba" and "bacab".
 Lexicographically, "abcba" comes before "bacab". Since k = 1, the output is "abcba".
 Constraints:
 1 <= s.length <= 104
 s consists of lowercase English letters.
 s is guaranteed to be palindromic.
 1 <= k <= 106
*/

char* smallestPalindrome(char* s, int k) {
    int n = strlen(s);
    int count[26] = {0};
    int oddCount = 0;
    char* result = (char*)malloc((n + 1) * sizeof(char));
    int index = 0;

    // Count frequency of each character
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    // Check if a palindromic rearrangement is possible
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) {
            oddCount++;
        }
    }
    
    if (oddCount > 1) {
        free(result);
        return ""; // No valid palindromic rearrangement
    }

    // Build the first half of the palindrome
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < count[i] / 2; j++) {
            result[index++] = 'a' + i;
        }
    }

    // If there is an odd character, place it in the middle
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) {
            result[index++] = 'a' + i;
            break;
        }
    }

    // Complete the palindrome by mirroring the first half
    for (int i = index - 1; i >= 0; i--) {
        result[index++] = result[i];
    }
    
    result[index] = '\0';

    // If k is greater than the number of distinct palindromic permutations, return empty string
    if (k > 1) {
        free(result);
        return ""; // Only one distinct palindromic permutation exists
    }

    return result;
    
}