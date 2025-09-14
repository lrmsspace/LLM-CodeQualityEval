/**https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/ */
//Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.
//Return the maximum possible product of the lengths of the two palindromic subsequences.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.
// 
//Example 1:
//Input: s = "leetcodecom"
//Output: 9
//Explanation: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
//The product of their lengths is: 3 * 3 = 9.
//Example 2:
//Input: s = "bb"
//Output: 1
//Explanation: An optimal solution is to choose "b" (the first character) for the 1st subsequence and "b" (the second character) for the 2nd subsequence.
//The product of their lengths is: 1 * 1 = 1.
//Example 3:
//Input: s = "accbcaxxcxx"
//Output: 25
//Explanation: An optimal solution is to choose "accca" for the 1st subsequence and "xxcxx" for the 2nd subsequence.
//The product of their lengths is: 5 * 5 = 25.
// 
//Constraints:
//	2 <= s.length <= 12
//	s consists of lowercase English letters only.
int maxProduct(char* s) {
    int n = strlen(s);
    int dp[n][n][2]; // dp[i][j][0]: the maximum product of length of subsequence ending at i, ending at j, and not including the middle character. dp[i][j][1]: the maximum product of length of subsequence ending at i, ending at j, including the middle character.
    
    memset(dp, 0, sizeof(dp));
    
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            
            if (len == 1) {
                dp[i][j][0] = 1;
                dp[i][j][1] = 1;
            } else if (len == 2) {
                dp[i][j][0] = 2;
                dp[i][j][1] = 2 * (s[i] == s[j]);
            } else {
                dp[i][j][0] = max(dp[i + 1][j][0], dp[i][j - 1][0]) * (s[i] == s[j]);
                dp[i][j][1] = max(dp[i + 1][j][1], dp[i][j - 1][1]) * (s[i] == s[j]) + dp[i + 1][j][0] * dp[i][j - 1][0];
            }
            
            // Update the maximum product of length of subsequence ending at i, ending at j.
            if (i < j) {
                dp[i][j][0] = max(dp[i][j][0], dp[i + 1][j][1] * dp[i][j - 1][0]);
            }
        }
        
        // Update the maximum product of length of subsequence ending at i, ending at n - 1.
        dp[i][n - 1][0] = max(dp[i][n - 1][0], dp[i + 1][n - 1][1] * dp[i][n - 2][0]);
    }
    
    return dp[0][n - 1][0];
}