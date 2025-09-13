/*
 You are given a string s and an integer k.
 In one operation, you can replace the character at any position with the next or previous letter in the alphabet (wrapping around so that 'a' is after 'z'). For example, replacing 'a' with the next letter results in 'b', and replacing 'a' with the previous letter results in 'z'. Similarly, replacing 'z' with the next letter results in 'a', and replacing 'z' with the previous letter results in 'y'.
 Return the length of the longest palindromic subsequence of s that can be obtained after performing at most k operations.
 Example 1:
 Input: s = "abced", k = 2
 Output: 3
 Explanation:
 Replace s[1] with the next letter, and s becomes "acced".
 Replace s[4] with the previous letter, and s becomes "accec".
 The subsequence "ccc" forms a palindrome of length 3, which is the maximum.
 Example 2:
 Input: s = "aaazzz", k = 4
 Output: 6
 Explanation:
 Replace s[0] with the previous letter, and s becomes "zaazzz".
 Replace s[4] with the next letter, and s becomes "zaazaz".
 Replace s[3] with the next letter, and s becomes "zaaaaz".
 The entire string forms a palindrome of length 6.
 Constraints:
 1 <= s.length <= 200
 1 <= k <= 200
 s consists of only lowercase English letters.
*/

int longestPalindromicSubsequence(char* s, int k) {
    int n = strlen(s);
    int dp[n][n];
    
    // Initialize the dp array
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1; // Each character is a palindrome of length 1
    }
    
    // Fill the dp array for substrings of length > 1
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2; // Characters match, extend the palindrome
            } else {
                dp[i][j] = fmax(dp[i + 1][j], dp[i][j - 1]); // Characters do not match, take the max
            }
        }
    }
    
    // The result is the longest palindromic subsequence length
    return dp[0][n - 1];
        
}