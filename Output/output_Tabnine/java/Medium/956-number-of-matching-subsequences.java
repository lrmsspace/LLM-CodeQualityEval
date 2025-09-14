/**https://leetcode.com/problems/number-of-matching-subsequences/ */
//Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
//A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
//	For example, "ace" is a subsequence of "abcde".
// 
//Example 1:
//Input: s = "abcde", words = ["a","bb","acd","ace"]
//Output: 3
//Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
//Example 2:
//Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
//Output: 2
// 
//Constraints:
//	1 <= s.length <= 5 * 104
//	1 <= words.length <= 5000
//	1 <= words[i].length <= 50
//	s and words[i] consist of only lowercase English letters.
class Solution {
    public int numMatchingSubseq(String s, String[] words) {
        int m = s.length(), n = words.length;
        int[][] dp = new int[n][m + 1];
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (s.charAt(i) == words[j].charAt(0)) {
                    dp[j][i + 1] = dp[j][i] + dp[j + 1][i];
                } else {
                    dp[j][i + 1] = dp[j + 1][i];
                }
            }
        }
        
        return dp[0][m];
        
    }
}