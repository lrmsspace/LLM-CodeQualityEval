/**https://leetcode.com/problems/palindrome-partitioning-iii/ */
//You are given a string s containing lowercase letters and an integer k. You need to :
//	First, change some characters of s to other lowercase English letters.
//	Then divide s into k non-empty disjoint substrings such that each substring is a palindrome.
//Return the minimal number of characters that you need to change to divide the string.
// 
//Example 1:
//Input: s = "abc", k = 2
//Output: 1
//Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.
//Example 2:
//Input: s = "aabbc", k = 3
//Output: 0
//Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.
//Example 3:
//Input: s = "leetcode", k = 8
//Output: 0
// 
//Constraints:
//	1 <= k <= s.length <= 100.
//	s only contains lowercase English letters.
class Solution {
    public int palindromePartition(String s, int k) {
        int n = s.length();
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = dp[i + 1][j - 1] + (s.charAt(i) == s.charAt(j) ? 0 : 1);
            }
        }
        int[][] f = new int[k + 1][n + 1];
        for (int i = 0; i <= k; i++) {
            Arrays.fill(f[i], Integer.MAX_VALUE);
        }
        f[0][0] = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = i - 1; j < n; j++) {
                for (int l = j + 1; l <= n; l++) {
                    f[i][l] = Math.min(f[i][l], f[i - 1][j] + dp[j][l - 1]);
                }
            }
        }
        return f[k][n];        
    }
}