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
    int len = strlen(s);
    int dp[len+1][len+1];
    int cost[len][len];
    memset(cost, 0, sizeof(cost));
    memset(dp, 0, sizeof(dp));
    for (int l = 2; l <= len; l++) {
        for (int i = 0; i <= len - l; i++) {
            int j = i + l - 1;
            cost[i][j] = s[i] == s[j] ? 0 : 1;
            if (l > 2) {
                cost[i][j] += cost[i+1][j-1];
            }
        }
    }
    for (int i = 1; i <= len; i++) {
        dp[i][1] = cost[0][i-1];
    }
    for (int i = 2; i <= len; i++) {
        for (int j = 2; j <= i && j <= k; j++) {
            dp[i][j] = INT_MAX;
            for (int l = 1; l < i; l++) {
                dp[i][j] = fmin(dp[i][j], dp[l][j-1] + cost[l][i-1]);
            }
        }
    }
    return dp[len][k];    
}