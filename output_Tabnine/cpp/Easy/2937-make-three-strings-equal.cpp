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
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 == 0 || n2 == 0 || n3 == 0) return max(n1, max(n2, n3));
        vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, 0)));
        for (int i = 1; i <= n1; i++) { 
            for (int j = 1; j <= n2; j++) {
                for (int k = 1; k <= n3; k++) {
                    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    } else {
                        dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
                    }
                }
            }
        }   
        return n1 + n2 + n3 - 2 * dp[n1][n2][n3];
        
    }
};