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

    int dp[n + 1][k + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = INT_MAX;
        }
    }

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int m = i - 1; m >= 0; m--) {
                int cost = 0;
                for (int l = m, r = i - 1; l < r; l++, r--) {
                    if (s[l] != s[r]) {
                        cost++;
                    }
                }
                dp[i][j] = min(dp[i][j], dp[m][j - 1] + cost);
            }
        }
    }

    return dp[n][k];
    
}