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
 1 <= words[i].length <= 5 * 104
 The input is generated such that sum(words[i].length) <= 105.
 words[i] consists only of lowercase English letters.
 1 <= target.length <= 5 * 104
 target consists only of lowercase English letters.
*/

int minValidStrings(char** words, int wordsSize, char* target) {
    int n = strlen(target);
    int dp[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = -1;
    }
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        if (dp[i] == -1) continue;
        for (int j = 0; j < wordsSize; j++) {
            int len = strlen(words[j]);
            for (int k = 1; k <= len && i + k <= n; k++) {
                if (strncmp(target + i, words[j], k) == 0) {
                    if (dp[i + k] == -1 || dp[i + k] > dp[i] + 1) {
                        dp[i + k] = dp[i] + 1;
                    }
                }
            }
        }
    }

    return dp[n];    
}