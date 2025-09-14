/**https://leetcode.com/problems/unique-length-3-palindromic-subsequences/ */
//Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
//Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
//A palindrome is a string that reads the same forwards and backwards.
//A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
//	For example, "ace" is a subsequence of "abcde".
// 
//Example 1:
//Input: s = "aabca"
//Output: 3
//Explanation: The 3 palindromic subsequences of length 3 are:
//- "aba" (subsequence of "aabca")
//- "aaa" (subsequence of "aabca")
//- "aca" (subsequence of "aabca")
//Example 2:
//Input: s = "adc"
//Output: 0
//Explanation: There are no palindromic subsequences of length 3 in "adc".
//Example 3:
//Input: s = "bbcbaba"
//Output: 4
//Explanation: The 4 palindromic subsequences of length 3 are:
//- "bbb" (subsequence of "bbcbaba")
//- "bcb" (subsequence of "bbcbaba")
//- "bab" (subsequence of "bbcbaba")
//- "aba" (subsequence of "bbcbaba")
// 
//Constraints:
//	3 <= s.length <= 105
//	s consists of only lowercase English letters.
int countPalindromicSubsequence(char* s) {
    int n = strlen(s);
    int dp[n][n][3];
    memset(dp, 0, sizeof(dp));
    
    // Initialize the base cases
    for (int i = 0; i < n; i++) {
        dp[i][i][0] = 1; // Single character is a palindrome
        dp[i][i][1] = 0; // No two adjacent characters are the same
        dp[i][i][2] = 1; // No other characters are the same
    }
    
    // Build up the dynamic programming table
    for (int len = 3; len <= n; len++) {
        for (int start = 0; start <= n - len; start++) {
            int end = start + len - 1;
            
            // If the characters at the start and end indices are the same
            if (s[start] == s[end]) {
                // There are three possible cases:
                // 1. The characters are the same, so we include the current character in the palindrome
                // 2. The characters are not the same, so we exclude the current character from the palindrome
                // 3. The characters are adjacent to each other, so we exclude both characters from the palindrome
                dp[start][end][0] = dp[start + 1][end - 1][0] + 1;
                dp[start][end][1] = dp[start + 1][end - 1][1] + dp[start][end - 1][1] + dp[start + 1][end][1];
                dp[start][end][2] = dp[start + 1][end - 1][2];
            } else {
                // The characters are not the same, so we include the current character in the palindrome
                dp[start][end][0] = dp[start + 1][end][0] + dp[start][end - 1][0];
                dp[start][end][1] = dp[start + 1][end][1] + dp[start][end - 1][1];
                dp[start][end][2] = dp[start + 1][end - 1][2] + 1;
            }
            
            // We only need the sum of the palindromes of length 3, so we can discard the intermediate results
            dp[start][end][0] %= 1000000007;
            dp[start][end][1] %= 1000000007;
            dp[start][end][2] %= 1000000007;
        }   
}
    
    // Return the sum of the palindromes of length 3
    return (dp[0][n - 1][0] + dp[0][n - 1][1] + dp[0][n - 1][2]) % 1000000007;
}
