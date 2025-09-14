/**https://leetcode.com/problems/palindrome-partitioning-ii/ */
//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return the minimum cuts needed for a palindrome partitioning of s.
// 
//Example 1:
//Input: s = "aab"
//Output: 1
//Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
//Example 2:
//Input: s = "a"
//Output: 0
//Example 3:
//Input: s = "ab"
//Output: 1
// 
//Constraints:
//	1 <= s.length <= 2000
//	s consists of lowercase English letters only.
class Solution {
    public int minCut(String s) {
        int n = s.length();
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; i - j >= 0 && i + j < n && s.charAt(i - j) == s.charAt(i + j); j++) {
                dp[i + j] = Math.min(dp[i + j], j == 0 ? -1 : dp[i - j - 1] + 1);
            }
            for (int j = 1; i - j + 1 >= 0 && i + j < n && s.charAt(i - j + 1) == s.charAt(i + j); j++) {
                dp[i + j] = Math.min(dp[i + j], j == 1 ? 0 : dp[i - j] + 1);
            }
        }
        return dp[n - 1];
    }
}