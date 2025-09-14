/**https://leetcode.com/problems/longest-palindromic-subsequence/ */
//Given a string s, find the longest palindromic subsequence's length in s.
//A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
// 
//Example 1:
//Input: s = "bbbab"
//Output: 4
//Explanation: One possible longest palindromic subsequence is "bbbb".
//Example 2:
//Input: s = "cbbd"
//Output: 2
//Explanation: One possible longest palindromic subsequence is "bb".
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists only of lowercase English letters.
int longestPalindromeSubseq(char * s){
    int len = strlen(s);
    int dp[len][len];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
    }
    for (int i = 1; i < len; i++) {
        dp[i - 1][i] = (s[i - 1] == s[i]) ? 2 : 1;
    }
    for (int i = 2; i < len; i++) {
        for (intj = i - 2; j >= 0; j--) {
            dp[j][i] = (s[j] == s[i]) ? dp[j + 1][i - 1] + 2 : max(dp[j + 1][i], dp[j][i - 1]);
}
    }
    return dp[0][len - 1];
}