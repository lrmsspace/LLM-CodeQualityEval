/**https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/ */
//You are given a binary string s and a positive integer k.
//Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.
//Note:
//	The subsequence can contain leading zeroes.
//	The empty string is considered to be equal to 0.
//	A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
// 
//Example 1:
//Input: s = "1001010", k = 5
//Output: 5
//Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in decimal.
//Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
//The length of this subsequence is 5, so 5 is returned.
//Example 2:
//Input: s = "00101001", k = 1
//Output: 6
//Explanation: "000001" is the longest subsequence of s that makes up a binary number less than or equal to 1, as this number is equal to 1 in decimal.
//The length of this subsequence is 6, so 6 is returned.
// 
//Constraints:
//	1 <= s.length <= 1000
//	s[i] is either '0' or '1'.
//	1 <= k <= 109
int longestSubsequence(char* s, int k) {
    int len = strlen(s);
    int dp[1001][32][2];
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l < 2; l++) {
                if (dp[i][j][l] == -1) {
                    continue;
                }
                if (dp[i][j][l] > dp[i + 1][j][l]) {
                    dp[i + 1][j][l] = dp[i][j][l];
                }
                if (l == 0) {
                    if (s[i] == '1') {
                        if (j + 1 <= k && dp[i][j][l] + 1 > dp[i + 1][j + 1][1]) {
                            dp[i + 1][j + 1][1] = dp[i][j][l] + 1;
                        }
                    } else {
                        if (dp[i][j][l] > dp[i + 1][j][0]) {
                            dp[i + 1][j][0] = dp[i][j][l];
                        }
                        if (j + 1 <= k && dp[i][j][l] + 1 > dp[i + 1][j + 1][1]) {
                            dp[i + 1][j + 1][1] = dp[i][j][l] + 1;
                        }
                    }
                } else {
                    if (dp[i][j][l] + 1 > dp[i + 1][j][1]) {
                        dp[i + 1][j][1] = dp[i][j][l] + 1;
                    }
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < 2; j++) {
            if (dp[len][i][j] > res) {
                res = dp[len][i][j];
            }
        }
    }
    return res;    
}