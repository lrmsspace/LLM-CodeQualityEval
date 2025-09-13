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
    int dp[101][101], n = strlen(s);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            if (s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1] == 0)) {
                dp[j][i] = 0;
            } else {
                dp[j][i] = 1 + dp[j + 1][i] + dp[j][i - 1] - dp[j + 1][i - 1];
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i += k) {
        res += dp[i][min(i + k - 1, n - 1)];
    }
    return res;
}