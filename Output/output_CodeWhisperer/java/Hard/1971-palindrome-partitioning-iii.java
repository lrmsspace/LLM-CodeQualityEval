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
        int[][] cost = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cost[i][j] = cost[i][j - 1] + (s.charAt(j) != s.charAt(i) ? 1 : 0);
            }
        }
        int[][] dp = new int[n][k + 1];
        for (int i = 0; i < n; i++) {
            dp[i][1] = cost[0][i];
            for (int j = 2; j <= k; j++) {
                dp[i][j] = n;
                for (int m = j - 2; m < i; m++) {
                    dp[i][j] = Math.min(dp[i][j], dp[m][j - 1] + cost[m + 1][i]);
                }
            }
        }
        return dp[n - 1][k];      
    }
}