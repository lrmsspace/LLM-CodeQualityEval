/*
 You are given three strings: s1, s2, and s3. In one operation you can choose one of these strings and delete its rightmost character. Note that you cannot completely empty a string.
 Return the minimum number of operations required to make the strings equal. If it is impossible to make them equal, return -1.
 Example 1:
 Input: s1 = "abc", s2 = "abb", s3 = "ab"
 Output: 2
 Explanation: Deleting the rightmost character from both s1 and s2 will result in three equal strings.
 Example 2:
 Input: s1 = "dac", s2 = "bac", s3 = "cac"
 Output: -1
 Explanation: Since the first letters of s1 and s2 differ, they cannot be made equal.
 Constraints:
 1 <= s1.length, s2.length, s3.length <= 100
 s1, s2 and s3 consist only of lowercase English letters.
*/

int findMinimumOperations(char* s1, char* s2, char* s3) {
    int m = strlen(s1);
    int n = strlen(s2);
    int p = strlen(s3);
    
    if (m!= n || m!= p) return -1;
    
    int dp[m + 1][n + 1][p + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= p; k++) {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1];
                } else {
                    dp[i][j][k] = min(min(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]) + 1;
                }
            }
        }
    }
    return dp[m][n][p];
    
    
}