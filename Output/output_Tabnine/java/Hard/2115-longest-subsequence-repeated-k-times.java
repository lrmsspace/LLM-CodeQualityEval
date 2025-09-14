/**https://leetcode.com/problems/longest-subsequence-repeated-k-times/ */
//You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
//A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.
//	For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
//Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.
// 
//Example 1:
//Input: s = "letsleetcode", k = 2
//Output: "let"
//Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
//"let" is the lexicographically largest one.
//Example 2:
//Input: s = "bb", k = 2
//Output: "b"
//Explanation: The longest subsequence repeated 2 times is "b".
//Example 3:
//Input: s = "ab", k = 2
//Output: ""
//Explanation: There is no subsequence repeated 2 times. Empty string is returned.
// 
//Constraints:
//	n == s.length
//	2 <= n, k <= 2000
//	2 <= n < k * 8
//	s consists of lowercase English letters.
class Solution {
    public String longestSubsequenceRepeatedK(String s, int k) {
        int n = s.length();
        int[] dp = new int[n + 1];
        int maxLen = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0 && s.charAt(j) == s.charAt(i - 1); j--) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
                maxLen = Math.max(maxLen, dp[i]);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = n; i >= 1 && maxLen >= k; i--) {
            if (dp[i] == maxLen) {
                sb.append(s.charAt(i - 1));
                maxLen--;
            }
        }
        return sb.toString();       
    }
}