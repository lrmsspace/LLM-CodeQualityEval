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
    int len = strlen(s);
    if (k > 26) return "";
    if (k > len / 2 + 1) return "";
    int i = 0;
    while (i < len / 2) {
        if (s[i] != s[len - i - 1]) {
            s[len - i - 1] = s[i];
            k--;
            if (k == 0) return s;
        }
        i++;
    }
    if (len % 2 == 1 && k > 1) {
        s[len / 2] = 'a';
        k--;
        if (k == 0) return s;
    }
    i = len / 2 - 1;
    while (i >= 0) {
        if (s[i] != 'z') {
            s[i]++;
            s[len - i - 1] = s[i];
            k--;
            if (k == 0) return s;
            int j = i + 1;
            while (j < len / 2) {
                s[j] = 'a';
                s[len - j - 1] = 'a';
                j++;
            }
            i = len / 2 - 1;
        } else {
            i--;
        }
    }
    return "";

}