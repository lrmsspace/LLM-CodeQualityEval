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
int longestPalindromeSubseq(char* s) {
    int n = strlen(s);
    int dp[n][n];
    
    // Initialize the diagonal elements of the dp array with 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    // Fill in the rest of the dp array using the LCS algorithm
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[0][n - 1];
    
}