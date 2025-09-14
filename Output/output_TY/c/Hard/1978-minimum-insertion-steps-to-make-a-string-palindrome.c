/**https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/ */
//Given a string s. In one step you can insert any character at any index of the string.
//Return the minimum number of steps to make s palindrome.
//A Palindrome String is one that reads the same backward as well as forward.
// 
//Example 1:
//Input: s = "zzazz"
//Output: 0
//Explanation: The string "zzazz" is already palindrome we do not need any insertions.
//Example 2:
//Input: s = "mbadm"
//Output: 2
//Explanation: String can be "mbdadbm" or "mdbabdm".
//Example 3:
//Input: s = "leetcode"
//Output: 5
//Explanation: Inserting 5 characters the string becomes "leetcodocteel".
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
int minInsertions(char * s){
    int len = strlen(s);
    int dp[len][len];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < len; i++) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < len - 1; i++) {
        dp[i][i + 1] = s[i] == s[i+ 1] ? 0 : 1;
    }
    for (int i = len - 3; i >= 0; i--) {
        for (int j = i + 2; j < len; j++) {
            dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : (dp[i + 1][j] < dp[i][j - 1] ? dp[i + 1][j] :dp[i][j - 1]) + 1;
        }
    }
    return dp[0][len - 1];
}