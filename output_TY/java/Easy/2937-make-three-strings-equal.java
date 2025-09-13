/*
 You are given three strings: s1, s2, and s3. In one operation you can choose one of these strings and delete its rightmost character. Note that you cannot completely empty a string.
 Return the minimum number of operations required to make the strings equal. If it is impossible to make them equal, return -1.
 Example 1:
 Input: s1 = "abc", s2 = "abb", s3 = "ab"
 Output: 2
 Explanation: Deleting the rightmost character from both s1 and s2 will result in three equal strings.
 Example 2:
 Input: s1 = "dac", s2 = "bac", s3 = "cac"
 Output: -1
 Explanation: Since the first letters of s1 and s2 differ, they cannot be made equal.
 Constraints:
 1 <= s1.length, s2.length, s3.length <= 100
 s1, s2 and s3 consist only of lowercase English letters.
*/

class Solution {
    public int findMinimumOperations(String s1, String s2, String s3) {
        
        int n = s1.length(), m = s2.length(), o = s3.length();
        int[][][] dp = new int[n + 1][m + 1][o + 1];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int k = 1; k <= o; k++) {
                    if(s1.charAt(i - 1) == s2.charAt(j - 1) && s2.charAt(j - 1) == s3.charAt(k - 1)) {
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    } else {
                        dp[i][j][k] = Math.max(dp[i - 1][j][k], Math.max( dp[i][j - 1][k], dp[i][j][k - 1])) ;
                    }
                }
            }
        }
        return dp[n][m][o];
    }
}