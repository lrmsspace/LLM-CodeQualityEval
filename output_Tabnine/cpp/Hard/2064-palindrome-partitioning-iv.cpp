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
class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        // Build a table to check if substring is palindrome
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            if (i < n - 1 && s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
            }
        }
        
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }
        
        // Check if s can be split into three non-empty palindromic substrings
        for (int i = 2; i < n; ++i) {
            if (dp[0][i - 1] && dp[i][n - 1]) {
                return true;
            }
        }
        
        return false;
        
    }
};