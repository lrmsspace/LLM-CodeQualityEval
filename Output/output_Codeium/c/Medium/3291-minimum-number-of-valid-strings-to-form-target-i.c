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
    int targetLen = strlen(target);
    int* dp = (int*)malloc((targetLen + 1) * sizeof(int));
    for (int i = 0; i <= targetLen; ++i) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    for (int i = 0; i < targetLen; ++i) {
        if (dp[i] == INT_MAX) continue;
        for (int j = 0; j < wordsSize; ++j) {
            int wordLen = strlen(words[j]);
            if (i + wordLen <= targetLen && strncmp(target + i, words[j], wordLen) == 0) {
                dp[i + wordLen] = fmin(dp[i + wordLen], dp[i] + 1);
            }
        }
    }

    int result = dp[targetLen] == INT_MAX ? -1 : dp[targetLen];
    free(dp);
    return result;
}

