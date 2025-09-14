/**https://leetcode.com/problems/count-palindromic-subsequences/ */
//Given a string of digits s, return the number of palindromic subsequences of s having length 5. Since the answer may be very large, return it modulo 109 + 7.
//Note:
//	A string is palindromic if it reads the same forward and backward.
//	A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
// 
//Example 1:
//Input: s = "103301"
//Output: 2
//Explanation: 
//There are 6 possible subsequences of length 5: "10330","10331","10301","10301","13301","03301". 
//Two of them (both equal to "10301") are palindromic.
//Example 2:
//Input: s = "0000000"
//Output: 21
//Explanation: All 21 subsequences are "00000", which is palindromic.
//Example 3:
//Input: s = "9999900000"
//Output: 2
//Explanation: The only two palindromic subsequences are "99999" and "00000".
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of digits.
int countPalindromes(char* s) {
    int n = strlen(s);
    long long MOD = 1e9 + 7;
    long long dp[n][n][5];
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i < n; ++i) {
        dp[i][i][0] = 1;
        dp[i][i][1] = 1;
        dp[i][i][2] = 1;
        dp[i][i][3] = 1;
        dp[i][i][4] = 1;
    }
    
    for (int len = 2; len <= 5; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j][0] = (dp[i + 1][j - 1][0] + dp[i + 1][j][0] + dp[i][j - 1][0]) % MOD;
                dp[i][j][1] = (dp[i + 1][j][1] + dp[i][j - 1][1] + dp[i + 1][j - 1][1]) % MOD;
                dp[i][j][2] = (dp[i + 1][j][2] + dp[i][j - 1][2] + dp[i + 1][j - 1][2]) % MOD;
    
                if (len == 5) {
                    dp[i][j][3] = (dp[i + 1][j][3] + dp[i][j - 1][3] + dp[i + 1][j - 1][3]) % MOD;
                    dp[i][j][4] = (dp[i + 1][j][4] + dp[i][j - 1][4] + dp[i + 1][j - 1][4]) % MOD;
                }


            } else {
                dp[i][j][0] = (dp[i + 1][j][0] + dp[i][j - 1][0]) % MOD;
                dp[i][j][1] = (dp[i + 1][j][1] + dp[i][j - 1][1]) % MOD;
                dp[i][j][2] = (dp[i + 1][j][2] + dp[i][j - 1][2]) % MOD;
                dp[i][j][3] = 0;
                dp[i][j][4] = 0;
            }
        }
    }
    
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        result = (result + dp[0][i][4]) % MOD;
    }
    
    return result;
    
}