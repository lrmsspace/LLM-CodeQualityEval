/**https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/ */
//You are given a string s and a positive integer k.
//Select a set of non-overlapping substrings from the string s that satisfy the following conditions:
//	The length of each substring is at least k.
//	Each substring is a palindrome.
//Return the maximum number of substrings in an optimal selection.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "abaccdbbd", k = 3
//Output: 2
//Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
//It can be shown that we cannot find a selection with more than two valid substrings.
//Example 2:
//Input: s = "adbcda", k = 2
//Output: 0
//Explanation: There is no palindrome substring of length at least 2 in the string.
// 
//Constraints:
//	1 <= k <= s.length <= 2000
//	s consists of lowercase English letters.
class Solution {
    public int maxPalindromes(String s, int k) {
        int n = s.length();
        int[][] dp = new int[n][n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    dp[i][j] = 1;
                } else if (s.charAt(i) == s.charAt(j)) {
                    if (j - i == 1 || dp[i + 1][j - 1] > 0) {
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    }
                }
            }
        }
        
        int[] dp2 = new int[n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = k; j <= n; j++) {
                dp2[j] = Math.max(dp2[j], dp[i][i + j - 1]);
            }
        }
        
        return dp2[n];
        
    }
}