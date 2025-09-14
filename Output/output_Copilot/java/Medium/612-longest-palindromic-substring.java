/**https://leetcode.com/problems/longest-palindromic-substring/ */
//Given a string s, return the longest palindromic substring in s.
// 
//Example 1:
//Input: s = "babad"
//Output: "bab"
//Explanation: "aba" is also a valid answer.
//Example 2:
//Input: s = "cbbd"
//Output: "bb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consist of only digits and English letters.
class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        if (n < 2) return s;
        boolean[][] dp = new boolean[n][n];
        int start = 0, maxLength = 1;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            dp[i][i + 1] = (s.charAt(i) == s.charAt(i + 1));
            if (dp[i][i + 1]) {
                start = i;
                maxLength = 2;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = (s.charAt(i) == s.charAt(j)) && dp[i + 1][j - 1];
                if (dp[i][j] && len > maxLength) {
                    start = i;
                    maxLength = len;
                }
            }
        }
        return s.substring(start, start + maxLength);        
    }
}