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
    int dp[n];
    memset(dp, 0x7f, sizeof(dp));
    dp[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        if (i+1 < n && s[i] == s[i+1]) dp[i] = min(dp[i], dp[i+2] + 1);
        for (int j = i+2; j < n; j++) {
            if (s[i] == s[j] && dp[j+1] != 0x7f7f7f7f) dp[i] = min(dp[i], dp[j+1] + 1);
        }
    }
    return dp[0];
}
