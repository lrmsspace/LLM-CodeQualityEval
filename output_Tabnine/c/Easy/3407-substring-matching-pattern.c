/*
 You are given a string s and a pattern string p, where p contains exactly one '*' character.
 The '*' in p can be replaced with any sequence of zero or more characters.
 Return true if p can be made a substring of s, and false otherwise.
 Example 1:
 Input: s = "leetcode", p = "ee*e"
 Output: true
 Explanation:
 By replacing the '*' with "tcod", the substring "eetcode" matches the pattern.
 Example 2:
 Input: s = "car", p = "c*v"
 Output: false
 Explanation:
 There is no substring matching the pattern.
 Example 3:
 Input: s = "luck", p = "u*"
 Output: true
 Explanation:
 The substrings "u", "uc", and "uck" match the pattern.
 Constraints:
 1 <= s.length <= 50
 1 <= p.length <= 50 
 s contains only lowercase English letters.
 p contains only lowercase English letters and exactly one '*'
*/

bool hasMatch(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);
    
    // If the pattern string has no '*', it must be a substring of the source string
    if (n == 1) {
        return strstr(s, p)!= NULL;
    }
    
    // Create a 2D DP table to store the results of subproblems
    bool dp[m + 1][n + 1];
    
    // Initialize the first row and first column of the DP table
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    
    // If the pattern string starts with '*', initialize the first column
    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i - 1][0] && (s[i - 1] == '*' || s[i - 1] == p[0]);
    }
    
    // Fill in the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
            }
        }
    }
    
    // Return the result
    return dp[m][n];
    
}