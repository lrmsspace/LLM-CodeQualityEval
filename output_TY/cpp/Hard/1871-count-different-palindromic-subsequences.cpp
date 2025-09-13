/**https://leetcode.com/problems/count-different-palindromic-subsequences/ */
//Given a string s, return the number of different non-empty palindromic subsequences in s. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence of a string is obtained by deleting zero or more characters from the string.
//A sequence is palindromic if it is equal to the sequence reversed.
//Two sequences a1, a2, ... and b1, b2, ... are different if there is some i for which ai != bi.
// 
//Example 1:
//Input: s = "bccb"
//Output: 6
//Explanation: The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
//Note that 'bcb' is counted only once, even though it occurs twice.
//Example 2:
//Input: s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
//Output: 104860361
//Explanation: There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 109 + 7.
// 
//Constraints:
//	1 <= s.length <= 1000
//	s[i] is either 'a', 'b', 'c', or 'd'.
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<int>> next(n, vector<int>(4, -1));
        vector<vector<int>> prev(n, vector<int>(4, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                if (s[i] == 'a' + j) {
                    prev[i][j] = i;
                } else {
                    prev[i][j] = prev[i - 1][j];
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                if (s[i] == 'a' + j) {
                    next[i][j] = i;
                } else {
                    next[i][j] = next[i + 1][j];
                }
            }
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 2;
            } else {
                dp[i][i + 1] = 1;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = 0;
                for (int k = 0; k < 4; k++) {
                    int l = prev[i][k];
                    int r = next[j][k];
                    if (l != -1 && r != -1) {
                        dp[i][j] += (dp[i][l] * dp[r][j]);
                    }
                }
                if (s[i] != s[j]) {
                    dp[i][j] += 2;
                } else {
                    dp[i][j] -= dp[i + 1][j - 1];
                }
            }
        }
        return dp[0][n - 1];
    }
};