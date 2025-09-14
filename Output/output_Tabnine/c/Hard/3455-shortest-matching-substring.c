/*
 You are given a string s and a pattern string p, where p contains exactly two '*' characters.
 The '*' in p matches any sequence of zero or more characters.
 Return the length of the shortest substring in s that matches p. If there is no such substring, return -1.
 Note: The empty substring is considered valid.
 Example 1:
 Input: s = "abaacbaecebce", p = "ba*c*ce"
 Output: 8
 Explanation:
 The shortest matching substring of p in s is "baecebce".
 Example 2:
 Input: s = "baccbaadbc", p = "cc*baa*adb"
 Output: -1
 Explanation:
 There is no matching substring in s.
 Example 3:
 Input: s = "a", p = "**"
 Output: 0
 Explanation:
 The empty substring is the shortest matching substring.
 Example 4:
 Input: s = "madlogic", p = "*adlogi*"
 Output: 6
 Explanation:
 The shortest matching substring of p in s is "adlogi".
 Constraints:
 1 <= s.length <= 105
 2 <= p.length <= 105
 s contains only lowercase English letters.
 p contains only lowercase English letters and exactly two '*'.
*/

int shortestMatchingSubstring(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);
    if (n < 2) {
        return -1;
    }
    
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    memset(dp, 0, (n + 1) * sizeof(int));
    
    int* next = (int*)malloc((n + 1) * sizeof(int));
    memset(next, -1, (n + 1) * sizeof(int));
    
    for (int i = 1; i <= n; i++) {
        if (p[i - 1] == '*') {
            next[i] = next[i - 2];
        } else {
            next[i] = i - 1;
        }
    }
    int maxLen = 0; 
    for (int i = 1; i <= m; i++) {
        dp[0] = i - 1;
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[j] = dp[j - 1] <= dp[j - 2]? dp[j - 1] : dp[j - 2];
            } else {
                dp[j] = s[i - 1] == p[j - 1]? dp[j - 1] + 1 : dp[j - 1];
            }
            maxLen = max(maxLen, dp[j]);
        }
    }
    free(dp);
    free(next);
    return maxLen == 0? -1 : maxLen;
    
}