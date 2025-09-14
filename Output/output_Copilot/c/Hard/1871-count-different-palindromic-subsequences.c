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
int countPalindromicSubsequences(char* s) {
    int n = strlen(s);
    int mod = 1000000007;
    int dp[1000][1000];
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                int left = i + 1, right = j - 1;
                while (left <= right && s[left] != s[i]) {
                    left++;
                }
                while (left <= right && s[right] != s[i]) {
                    right--;
                }
                if (left > right) {
                    dp[i][j] = 2 * dp[i + 1][j - 1] + 2;
                } else if (left == right) {
                    dp[i][j] = 2 * dp[i + 1][j - 1] + 1;
                } else {
                    dp[i][j] = 2 * dp[i + 1][j - 1] - dp[left + 1][right - 1];
                }
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
            }
            dp[i][j] = dp[i][j] < 0 ? dp[i][j] + mod : dp[i][j] % mod;
        }
    }
    return dp[0][n - 1];  
}