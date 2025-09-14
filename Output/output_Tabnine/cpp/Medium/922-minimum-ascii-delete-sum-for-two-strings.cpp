/**https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/ */
//Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.
// 
//Example 1:
//Input: s1 = "sea", s2 = "eat"
//Output: 231
//Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
//Deleting "t" from "eat" adds 116 to the sum.
//At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
//Example 2:
//Input: s1 = "delete", s2 = "leet"
//Output: 403
//Explanation: Deleting "dee" from "delete" to turn the string into "let",
//adds 100[d] + 101[e] + 101[e] to the sum.
//Deleting "e" from "leet" adds 101[e] to the sum.
//At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
//If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
// 
//Constraints:
//	1 <= s1.length, s2.length <= 1000
//	s1 and s2 consist of lowercase English letters.
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = m - 1; i >= 0; --i) {
            dp[i][n] = dp[i + 1][n] + s1[i];
        }
        
        for (int j = n - 1; j >= 0; --j) {
            dp[m][j] = dp[m][j + 1] + s2[j];
        }
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = min(dp[i + 1][j] + s1[i], dp[i][j + 1] + s2[j]);
                dp[i][j] = min(dp[i][j], dp[i + 1][j + 1] + (s1[i] == s2[j]? 0 : s1[i] + s2[j]));
            }
        }
        
        return dp[0][0];
        
    }
};