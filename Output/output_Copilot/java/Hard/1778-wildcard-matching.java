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
    public boolean isMatch(String s, String p) {
        int sLen = s.length(), pLen = p.length();
        boolean[][] dp = new boolean[sLen + 1][pLen + 1];
        dp[0][0] = true; // Empty string matches empty pattern

        for (int j = 1; j <= pLen; j++) {
            if (p.charAt(j - 1) == '*') {
                dp[0][j] = dp[0][j - 1]; // '*' can match zero occurrences of the preceding element
            }
        }

        for (int i = 1; i <= sLen; i++) {
            for (int j = 1; j <= pLen; j++) {
                char sChar = s.charAt(i - 1);
                char pChar = p.charAt(j - 1);

                if (sChar == pChar || pChar == '?') {
                    dp[i][j] = dp[i - 1][j - 1]; // Characters match or '?' matches any character
                } else if (pChar == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j]; // '*' can match zero or more of the preceding element
                }
            }
        }

        return dp[sLen][pLen]; // Return whether the entire string matches the entire pattern    
    }
}