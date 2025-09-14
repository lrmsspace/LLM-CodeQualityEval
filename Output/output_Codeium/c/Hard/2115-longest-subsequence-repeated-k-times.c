/**https://leetcode.com/problems/longest-subsequence-repeated-k-times/ */
//You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
//A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.
//	For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
//Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.
// 
//Example 1:
//Input: s = "letsleetcode", k = 2
//Output: "let"
//Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
//"let" is the lexicographically largest one.
//Example 2:
//Input: s = "bb", k = 2
//Output: "b"
//Explanation: The longest subsequence repeated 2 times is "b".
//Example 3:
//Input: s = "ab", k = 2
//Output: ""
//Explanation: There is no subsequence repeated 2 times. Empty string is returned.
// 
//Constraints:
//	n == s.length
//	2 <= n, k <= 2000
//	2 <= n < k * 8
//	s consists of lowercase English letters.
char* longestSubsequenceRepeatedK(char* s, int k) {
    int n = strlen(s);
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (s[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int len = dp[n][n];
    char* res = (char*)malloc((len + 1) * sizeof(char));
    int idx = 0;
    for (int i = n; i > 0; --i) {
        if (dp[i][i] == dp[i - 1][i - 1] + 1) {
            res[idx++] = s[i - 1];
        }
    }
    res[idx] = '\0';
    reverse(res, res + idx);
    while (idx > 0 && k-- > 1) {
        strcat(res, res);
        idx *= k;
    }
    return res;
}