/**https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/ */
//You are given a digit string s that consists of digits from 0 to 9.
//A string is called semi-repetitive if there is at most one adjacent pair of the same digit. For example, "0010", "002020", "0123", "2002", and "54944" are semi-repetitive while the following are not: "00101022" (adjacent same digit pairs are 00 and 22), and "1101234883" (adjacent same digit pairs are 11 and 88).
//Return the length of the longest semi-repetitive substring of s.
// 
//Example 1:
//Input: s = "52233"
//Output: 4
//Explanation:
//The longest semi-repetitive substring is "5223". Picking the whole string "52233" has two adjacent same digit pairs 22 and 33, but at most one is allowed.
//Example 2:
//Input: s = "5494"
//Output: 4
//Explanation:
//s is a semi-repetitive string.
//Example 3:
//Input: s = "1111111"
//Output: 2
//Explanation:
//The longest semi-repetitive substring is "11". Picking the substring "111" has two adjacent same digit pairs, but at most one is allowed.
// 
//Constraints:
//	1 <= s.length <= 50
//	'0' <= s[i] <= '9'
int longestSemiRepetitiveSubstring(char* s) {
    int n = strlen(s);
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        maxLen = max(maxLen, 1);
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && len == 2) {
                dp[i][j] = 2;
            } else if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    return maxLen;
}