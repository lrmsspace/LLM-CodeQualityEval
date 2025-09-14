/*
 You are given an array of strings words and a string target.
 A string x is called valid if x is a prefix of any string in words.
 Return the minimum number of valid strings that can be concatenated to form target. If it is not possible to form target, return -1.
 Example 1:
 Input: words = ["abc","aaaaa","bcdef"], target = "aabcdabc"
 Output: 3
 Explanation:
 The target string can be formed by concatenating:
 Prefix of length 2 of words[1], i.e. "aa".
 Prefix of length 3 of words[2], i.e. "bcd".
 Prefix of length 3 of words[0], i.e. "abc".
 Example 2:
 Input: words = ["abababab","ab"], target = "ababaababa"
 Output: 2
 Explanation:
 The target string can be formed by concatenating:
 Prefix of length 5 of words[0], i.e. "ababa".
 Prefix of length 5 of words[0], i.e. "ababa".
 Example 3:
 Input: words = ["abcdef"], target = "xyz"
 Output: -1
 Constraints:
 1 <= words.length <= 100
 1 <= words[i].length <= 5 * 103
 The input is generated such that sum(words[i].length) <= 105.
 words[i] consists only of lowercase English letters.
 1 <= target.length <= 5 * 103
 target consists only of lowercase English letters.
*/

int minValidStrings(char** words, int wordsSize, char* target) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int len = strlen(target);
    int dp[len + 1];
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]);
        if (len > len) {
            continue;
        }
        for (j = len; j <= len; j++) {
            dp[j] = 1;
        }
    }
    if (dp[len] == 0) {
        return -1;
    }
    for (i = 1; i <= len; i++) {
        if (dp[i] == 0) {
            continue;
        }
        for (j = 0; j < wordsSize; j++) {
            int len = strlen(words[j]);
            if (i + len > len) {
                continue;
            }
            if (strncmp(target + i, words[j], len) == 0) {
                dp[i + len] = 1;
            }
        }
    }
    if (dp[len] == 0) {
        return -1;
    }
    int count = 0;
    for (i = len; i > 0; i--) {
        if (dp[i] == 1) {
            count++;
            i--;
        }
    }
    return count;

}