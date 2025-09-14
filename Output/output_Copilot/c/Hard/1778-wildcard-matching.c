/**https://leetcode.com/problems/wildcard-matching/ */
//Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
//	'?' Matches any single character.
//	'*' Matches any sequence of characters (including the empty sequence).
//The matching should cover the entire input string (not partial).
// 
//Example 1:
//Input: s = "aa", p = "a"
//Output: false
//Explanation: "a" does not match the entire string "aa".
//Example 2:
//Input: s = "aa", p = "*"
//Output: true
//Explanation: '*' matches any sequence.
//Example 3:
//Input: s = "cb", p = "?a"
//Output: false
//Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
// 
//Constraints:
//	0 <= s.length, p.length <= 2000
//	s contains only lowercase English letters.
//	p contains only lowercase English letters, '?' or '*'.
bool isMatch(char* s, char* p) {
    int len_s = strlen(s);
    int len_p = strlen(p);
    bool dp[len_s+1][len_p+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    for (int i = 1; i <= len_p; i++) {
        if (p[i-1] == '*') {
            dp[0][i] = dp[0][i-1];
        }
    }
    for (int i = 1; i <= len_s; i++) {
        for (int j = 1; j <= len_p; j++) {
            if (p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            } else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    return dp[len_s][len_p];    
}