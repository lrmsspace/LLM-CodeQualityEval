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
        int n = s.length(), dp[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
            for (int j = i - 1; j >= 0; j--) {
                dp[j][i] = dp[j + 1][i - 1] + (s.charAt(j) != s.charAt(i) ? 1 : 0);
            }
        }
        int[] dp2 = new int[n];
        Arrays.fill(dp2, Integer.MAX_VALUE);
        dp2[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                dp2[i] = Math.min(dp2[i], dp2[j] + dp[j][i - 1]);
            }
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < n - k + 1; i++) {
            res = Math.min(res, dp2[i + k - 1]);
        }
        return res;
    }
}