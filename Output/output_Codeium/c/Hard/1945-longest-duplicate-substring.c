/**https://leetcode.com/problems/longest-duplicate-substring/ */
//Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
//Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".
// 
//Example 1:
//Input: s = "banana"
//Output: "ana"
//Example 2:
//Input: s = "abcd"
//Output: ""
// 
//Constraints:
//	2 <= s.length <= 3 * 104
//	s consists of lowercase English letters.
char* longestDupSubstring(char* s) {
    int n = strlen(s);
    char* dp = (char*)malloc(n * n * sizeof(char));
    int max_len = 0, max_start = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i * n + j] = 1;
                if (i > 0 && dp[(i - 1) * n + (j - 1)]) {
                    dp[i * n + j] += dp[(i - 1) * n + (j - 1)];
                }
                if (dp[i * n + j] > max_len) {
                    max_len = dp[i * n + j];
                    max_start = i - max_len + 1;
                }
            }
        }
    }
    char* res = (char*)malloc((max_len + 1) * sizeof(char));
    strncpy(res, s + max_start, max_len);
    res[max_len] = 0;
    free(dp);
    return res;
}