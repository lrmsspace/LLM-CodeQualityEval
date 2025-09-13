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
        boolean[][] dp = new boolean[n][n];
        int[] cuts = new int[n + 1];
        
        // Initialize dp and cuts
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            cuts[i] = i;
        }
        
        // Build dp table
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                if (s.charAt(i) == s.charAt(j) && (l == 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    cuts[j] = Math.min(cuts[j], cuts[i] + 1);
                }
            }
        }
        
        // Return the minimum cuts
        return cuts[n - 1];
        
    }
}