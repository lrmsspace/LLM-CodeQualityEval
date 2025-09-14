/*
 Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
 You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.
 Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.
 Since the answer may be very large, return it modulo 109 + 7.
 Example 1:
 Input: word = "aabbccdd", k = 7
 Output: 5
 Explanation:
 The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".
 Example 2:
 Input: word = "aabbccdd", k = 8
 Output: 1
 Explanation:
 The only possible string is "aabbccdd".
 Example 3:
 Input: word = "aaabbb", k = 3
 Output: 8
 Constraints:
 1 <= word.length <= 5 * 105
 word consists only of lowercase English letters.
 1 <= k <= 2000
*/

int possibleStringCount(char* word, int k) {
    int n = strlen(word);
    int mod = 1000000007;
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = i - 1; l >= 0; l--) {
                if (word[l] != word[i - 1]) {
                    break;
                }
                if (j - (i - l) >= 0) {
                    dp[i][j] = (dp[i][j] + dp[l][j - (i - l)]) % mod;
                }
            }
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
        }
    }
    return dp[n][k];    
}