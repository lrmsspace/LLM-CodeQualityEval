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
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < m; i++) {
            if (p[i] == '*') {
                dp[0][i + 1] = dp[0][i];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (p[j] == '*') {
                    dp[i + 1][j+ 1] = dp[i][j + 1]  || dp[i + 1][j];
                    if (dp[i + 1][j + 1]) {
                        dp[i + 1][j + 1] = (s[i] == p[j] || p[j] == '?') && dp[i][j];
                    }
                    continue;
                }
            }
        }
        return dp[n][m];
    }
};