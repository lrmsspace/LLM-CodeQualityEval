/**https://leetcode.com/problems/strange-printer/ */
//There is a strange printer with the following two special properties:
//	The printer can only print a sequence of the same character each time.
//	At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
//Given a string s, return the minimum number of turns the printer needed to print it.
// 
//Example 1:
//Input: s = "aaabbb"
//Output: 2
//Explanation: Print "aaa" first and then print "bbb".
//Example 2:
//Input: s = "aba"
//Output: 2
//Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of lowercase English letters.
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Initialize the base cases
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        // Build up the dynamic programming table
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = len;
                
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (s[i]!= s[k + 1]));
                }
            }
        }
        
        return dp[0][n - 1];
        
    }
};