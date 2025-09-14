/**https://leetcode.com/problems/palindrome-partitioning-iv/ */
//Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​
//A string is said to be palindrome if it the same string when reversed.
// 
//Example 1:
//Input: s = "abcbdd"
//Output: true
//Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
//Example 2:
//Input: s = "bcbddxy"
//Output: false
//Explanation: s cannot be split into 3 palindromes.
// 
//Constraints:
//	3 <= s.length <= 2000
//	s​​​​​​ consists only of lowercase English letters.
bool checkPartitioning(char* s) {
    int n = strlen(s);
    int dp[n][n];
    memset(dp, false, sizeof(dp));
    
    // Build a table[i][j] to store whether s[i...j] is a palindrome
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
        if (i + 1 < n && s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
        }
    }
    
    // Build the table in bottom-up manner
    for (int l = 3; l <= n; ++l) {
        for (int i = 0; i <= n - l; ++i) {
            int j = i + l - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
            }
        }
    }
    
    // Check if s can be split into three palindromic substrings
    for (int i = 2; i < n; ++i) {
        if (dp[0][i - 1] && dp[i][n - 1]) {
            return true;
        }
    }
    
    return false;
    
}