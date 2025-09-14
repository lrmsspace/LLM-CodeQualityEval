/**https://leetcode.com/problems/longest-ideal-subsequence/ */
//You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:
//	t is a subsequence of the string s.
//	The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
//Return the length of the longest ideal string.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
//Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.
// 
//Example 1:
//Input: s = "acfgbd", k = 2
//Output: 4
//Explanation: The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
//Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.
//Example 2:
//Input: s = "abcd", k = 3
//Output: 4
//Explanation: The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.
// 
//Constraints:
//	1 <= s.length <= 105
//	0 <= k <= 25
//	s consists of lowercase English letters.
class Solution {
    public int longestIdealString(String s, int k) {
        int n = s.length();
        int[][] dp = new int[n][26];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == 0) {
                    dp[i][j] = (s.charAt(i) - 'a' == j) ? 1 : 0;
                } else {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                    if (j > 0) {
                        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1]);
                    }
                    if (j < 25) {
                        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j + 1]);
                    }
                    if (s.charAt(i) - 'a' == j) {
                        dp[i][j]++;
                    }
                }
                ans = Math.max(ans, dp[i][j]);
            }
        }
        return ans;        
    }
}