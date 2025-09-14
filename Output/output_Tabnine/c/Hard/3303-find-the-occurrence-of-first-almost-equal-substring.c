/*
 You are given two strings s and pattern.
 A string x is called almost equal to y if you can change at most one character in x to make it identical to y.
 Return the smallest starting index of a substring in s that is almost equal to pattern. If no such index exists, return -1.
 A substring is a contiguous non-empty sequence of characters within a string.
 Example 1:
 Input: s = "abcdefg", pattern = "bcdffg"
 Output: 1
 Explanation:
 The substring s[1..6] == "bcdefg" can be converted to "bcdffg" by changing s[4] to "f".
 Example 2:
 Input: s = "ababbababa", pattern = "bacaba"
 Output: 4
 Explanation:
 The substring s[4..9] == "bababa" can be converted to "bacaba" by changing s[6] to "c".
 Example 3:
 Input: s = "abcd", pattern = "dba"
 Output: -1
 Example 4:
 Input: s = "dde", pattern = "d"
 Output: 0
 Constraints:
 1 <= pattern.length < s.length <= 105
 s and pattern consist only of lowercase English letters.
 Follow-up: Could you solve the problem if at most k consecutive characters can be changed?
*/

int minStartingIndex(char* s, char* pattern) {
    int sLen = strlen(s);
    int pLen = strlen(pattern);
    int k = 0; // Maximum consecutive changes allowed
    
    // Initialize a 2D array dp[][] to store the minimum starting index
    int dp[sLen + 1][pLen + 1];
    memset(dp, 0x3f, sizeof(dp));
    
    // Base case: if pattern is empty, return 0
    for (int i = 0; i <= sLen; i++) {
        dp[i][0] = i;
    }
    // Base case: if s is empty, return -1
    for (int j = 1; j <= pLen; j++) {
        dp[0][j] = j;
    }
    
    // Fill the dp[][] table
    for (int i = 1; i <= sLen; i++) {
        for (int j = 1; j <= pLen; j++) {
            if (s[i - 1] == pattern[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }
    
    // Find the minimum starting index
    int minIndex = INT_MAX;
    for (int i = 1; i <= sLen - pLen + 1; i++) {
        if (dp[i + pLen - 1][pLen] <= k) {
            minIndex = min(minIndex, i);
        }
    }
    
    return minIndex == INT_MAX? -1 : minIndex;
    
}