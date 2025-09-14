/**https://leetcode.com/problems/palindrome-partitioning-iii/ */
//You are given a string s containing lowercase letters and an integer k. You need to :
//	First, change some characters of s to other lowercase English letters.
//	Then divide s into k non-empty disjoint substrings such that each substring is a palindrome.
//Return the minimal number of characters that you need to change to divide the string.
// 
//Example 1:
//Input: s = "abc", k = 2
//Output: 1
//Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.
//Example 2:
//Input: s = "aabbc", k = 3
//Output: 0
//Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.
//Example 3:
//Input: s = "leetcode", k = 8
//Output: 0
// 
//Constraints:
//	1 <= k <= s.length <= 100.
//	s only contains lowercase English letters.
int palindromePartition(char* s, int k) {
    int n = strlen(s);
    int dp[n][n];
    memset(dp, 0x3f, sizeof(dp));
    
    // Single character palindromes
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 0;
    }
    
    // Two-character palindromes
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 0;
        }
    }
    
    // Build up the dp table
    for (int len = 3; len <= n; ++len) {
        for (int start = 0; start <= n - len; ++start) {
            int end = start + len - 1;
            if (s[start] == s[end]) {
                dp[start][end] = dp[start + 1][end - 1];
            } else {
                dp[start][end] = min(dp[start + 1][end], dp[start][end - 1]) + 1;
            }
        }
    }
    
    // Find the minimum number of changes
    int minChanges = INT_MAX;
    for (int i = 0; i < n - k + 1; ++i) {
        minChanges = min(minChanges, dp[i][n - 1] + k - (n - i - 1));
    }
    
    return minChanges;
    
}