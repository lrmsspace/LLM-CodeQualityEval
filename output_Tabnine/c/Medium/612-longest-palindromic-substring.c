/**https://leetcode.com/problems/longest-palindromic-substring/ */
//Given a string s, return the longest palindromic substring in s.
// 
//Example 1:
//Input: s = "babad"
//Output: "bab"
//Explanation: "aba" is also a valid answer.
//Example 2:
//Input: s = "cbbd"
//Output: "bb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consist of only digits and English letters.
char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n <= 1) return s;
    
    // Initialize result and start index
    int maxLength = 1, start = 0;
    
    // Create a 2D array to store the palindrome substrings
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    
    // Single character substrings are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    
    // Check for two-character substrings
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            maxLength = 2;
            start = i;
        }
    }
    
    // Check for longer palindromes
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                maxLength = length;
                start = i;
            }
        }
    }
    
    // Allocate memory for the longest palindromic substring
    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    strncpy(result, s + start, maxLength);
    result[maxLength] = '\0';
    
    return result;
}