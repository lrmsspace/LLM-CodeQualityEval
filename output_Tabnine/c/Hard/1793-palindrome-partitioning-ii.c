/**https://leetcode.com/problems/palindrome-partitioning-ii/ */
//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return the minimum cuts needed for a palindrome partitioning of s.
// 
//Example 1:
//Input: s = "aab"
//Output: 1
//Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
//Example 2:
//Input: s = "a"
//Output: 0
//Example 3:
//Input: s = "ab"
//Output: 1
// 
//Constraints:
//	1 <= s.length <= 2000
//	s consists of lowercase English letters only.
int minCut(char* s) {
    int n = strlen(s);
    bool dp[n][n];
    int cut[n];
    
    // Initialize dp and cut arrays
    memset(dp, false, sizeof(dp));
    memset(cut, 0, sizeof(cut));
    
    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        cut[i] = 0;
    }
    
    // Check for substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            cut[i + 1] = 1;
        }
    }
    
    // Check for substrings of length greater than 2
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                cut[i] = min(cut[i], cut[i + 1] + 1);
            }
        }
    }
    
    // Return the minimum cuts needed
    return cut[0];
    
}