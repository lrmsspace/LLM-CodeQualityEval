/**https://leetcode.com/problems/distinct-subsequences-ii/ */
//Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.
// 
//Example 1:
//Input: s = "abc"
//Output: 7
//Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
//Example 2:
//Input: s = "aba"
//Output: 6
//Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".
//Example 3:
//Input: s = "aaa"
//Output: 3
//Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
// 
//Constraints:
//	1 <= s.length <= 2000
//	s consists of lowercase English letters.
int distinctSubseqII(char* s) {
    int len = strlen(s);
    int mod = 1000000007;
    int dp[len+1];
    dp[0] = 1;
    int last[26];
    memset(last, -1, sizeof(last));
    for (int i = 1; i <= len; i++) {
        dp[i] = (dp[i-1] * 2) % mod;
        if (last[s[i-1] - 'a'] != -1) {
            dp[i] -= dp[last[s[i-1] - 'a'] - 1];
        }
        dp[i] = (dp[i] + mod) % mod;
        last[s[i-1] - 'a'] = i;
    }
    return dp[len] - 1;    
}