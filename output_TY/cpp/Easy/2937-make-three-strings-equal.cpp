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
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), o = s3.size();
        int dp[n + 1][m + 1][o + 1];
        memset(dp, -1, sizeof(dp));
        dp[n][m][o] = 0;
        for (int i = n; i >= 0; i--) {
            for (int j = m; j >= 0; j--) {
                for (int k = o; k >= 0; k--) {
                    if (i < n && j < m && k < o && s1[i] == s2[j] && s2[j] == s3[k]) {  
                        dp[i][j][k] = 1 + dp[i + 1][j + 1][k + 1];
}
                }
            }
        }
        return dp[0][0][0] == s1.size() ? 1 : 0;
    }
};