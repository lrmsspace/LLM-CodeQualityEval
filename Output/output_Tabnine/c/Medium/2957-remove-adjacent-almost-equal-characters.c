/*
 You are given a 0-indexed string word.
 In one operation, you can pick any index i of word and change word[i] to any lowercase English letter.
 Return the minimum number of operations needed to remove all adjacent almost-equal characters from word.
 Two characters a and b are almost-equal if a == b or a and b are adjacent in the alphabet.
 Example 1:
 Input: word = "aaaaa"
 Output: 2
 Explanation: We can change word into "acaca" which does not have any adjacent almost-equal characters.
 It can be shown that the minimum number of operations needed to remove all adjacent almost-equal characters from word is 2.
 Example 2:
 Input: word = "abddez"
 Output: 2
 Explanation: We can change word into "ybdoez" which does not have any adjacent almost-equal characters.
 It can be shown that the minimum number of operations needed to remove all adjacent almost-equal characters from word is 2.
 Example 3:
 Input: word = "zyxyxyz"
 Output: 3
 Explanation: We can change word into "zaxaxaz" which does not have any adjacent almost-equal characters. 
 It can be shown that the minimum number of operations needed to remove all adjacent almost-equal characters from word is 3.
 Constraints:
 1 <= word.length <= 100
 word consists only of lowercase English letters.
*/

int removeAlmostEqualCharacters(char* word) {
    int n = strlen(word);
    int dp[n][n][26];
    memset(dp, -1, sizeof(dp));
    
    // Base case: if the word has only one character, no operations are needed
    for (int i = 0; i < n; i++) {
        dp[i][i][word[i] - 'a'] = 0;
    }   
    // Fill the dp table
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            for (int k = 0; k < 26; k++) {
                if (k == word[i] - 'a' || k == word[j] - 'a') {
                    // If the current character is the same as the previous or next character, skip it
                    continue;
                }
                int minOp = INT_MAX;
                for (int l = i; l < j; l++) {
                    minOp = min(minOp, dp[i][l][k] + dp[l + 1][j][word[i] - 'a'] + dp[l][j][word[j] - 'a']);
                }
                dp[i][j][k] = minOp;
            }
        }
    }   
    // Find the minimum number of operations needed to remove all adjacent almost-equal characters
    int minOp = INT_MAX;
    for (int k = 0; k < 26; k++) {
        minOp = min(minOp, dp[0][n - 1][k]);
    }
    return minOp;
    
}