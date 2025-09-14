/**https://leetcode.com/problems/distinct-subsequences/ */
//Given two strings s and t, return the number of distinct subsequences of s which equals t.
//The test cases are generated so that the answer fits on a 32-bit signed integer.
// 
//Example 1:
//Input: s = "rabbbit", t = "rabbit"
//Output: 3
//Explanation:
//As shown below, there are 3 ways you can generate "rabbit" from s.
//rabbbit
//rabbbit
//rabbbit
//Example 2:
//Input: s = "babgbag", t = "bag"
//Output: 5
//Explanation:
//As shown below, there are 5 ways you can generate "bag" from s.
//babgbag
//babgbag
//babgbag
//babgbag
//babgbag
// 
//Constraints:
//	1 <= s.length, t.length <= 1000
//	s and t consist of English letters.
int numDistinct(char * s, char * t){
    int len_s = strlen(s);
    int len_t = strlen(t);
    int dp[len_s + 1][len_t + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= len_s; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= len_s; i++) {
        for (int j = 1; j <= len_t; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[len_s][len_t];
}