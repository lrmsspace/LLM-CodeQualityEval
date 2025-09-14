/*
 You are given two strings word1 and word2.
 A string x is called valid if x can be rearranged to have word2 as a prefix.
 Return the total number of valid substrings of word1.
 Example 1:
 Input: word1 = "bcca", word2 = "abc"
 Output: 1
 Explanation:
 The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.
 Example 2:
 Input: word1 = "abcabc", word2 = "abc"
 Output: 10
 Explanation:
 All the substrings except substrings of size 1 and size 2 are valid.
 Example 3:
 Input: word1 = "abcabc", word2 = "aaabc"
 Output: 0
 Constraints:
 1 <= word1.length <= 105
 1 <= word2.length <= 104
 word1 and word2 consist only of lowercase English letters.
*/

long long validSubstringCount(char* word1, char* word2) {
    int count = 0;
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    for (int i = 0; i <= len1 - len2; i++) {
        char* substring = strndup(word1 + i, len2);
        if (canRearrange(substring, word2)) {
            count++;
        }
        free(substring);
    }
    return count;
}

bool canRearrange(char* s1, char* s2) {
    int count[26] = {0};
    for (int i = 0; s1[i]; i++) {
        count[s1[i] - 'a']++;
    }
    for (int i = 0; s2[i]; i++) {
        if (--count[s2[i] - 'a'] < 0) {
            return false;
        }
    }
    return true;
}