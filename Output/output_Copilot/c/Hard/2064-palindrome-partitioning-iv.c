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
    bool dp[n][n];
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (len == 2) {
                dp[i][j] = s[i] == s[j];
            } else {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
            }
        }
    }
    for (int i = 0; i < n - 2; i++) {
        if (!dp[0][i]) {
            continue;
        }
        for (int j = i + 1; j < n - 1; j++) {
            if (!dp[i + 1][j]) {
                continue;
            }
            if (dp[j + 1][n - 1]) {
                return true;
            }
        }
    }
    return false;    
}