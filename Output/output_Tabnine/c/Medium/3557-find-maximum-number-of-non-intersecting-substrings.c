/*
 You are given a string word.
 Return the maximum number of non-intersecting substrings of word that are at least four characters long and start and end with the same letter.
 Example 1:
 Input: word = "abcdeafdef"
 Output: 2
 Explanation:
 The two substrings are "abcdea" and "fdef".
 Example 2:
 Input: word = "bcdaaaab"
 Output: 1
 Explanation:
 The only substring is "aaaa". Note that we cannot also choose "bcdaaaab" since it intersects with the other substring.
 Constraints:
 1 <= word.length <= 2 * 105
 word consists only of lowercase English letters.
*/

int maxSubstrings(char* word) {
    int n = strlen(word);
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    
    int maxCount = 0;
    for (int len = 4; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (word[i] == word[j] && len >= 4) {
                if (len == 4) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i + 1][j - 1] + 1;
                }
                maxCount = max(maxCount, dp[i][j]);
            }
        }
    }
    
    return maxCount;
    
}