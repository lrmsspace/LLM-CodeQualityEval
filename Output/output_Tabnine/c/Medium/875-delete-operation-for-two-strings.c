/**https://leetcode.com/problems/delete-operation-for-two-strings/ */
//Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
//In one step, you can delete exactly one character in either string.
// 
//Example 1:
//Input: word1 = "sea", word2 = "eat"
//Output: 2
//Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
//Example 2:
//Input: word1 = "leetcode", word2 = "etco"
//Output: 4
// 
//Constraints:
//	1 <= word1.length, word2.length <= 500
//	word1 and word2 consist of only lowercase English letters.
int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    int dp[m+1][n+1];
    
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
    
}