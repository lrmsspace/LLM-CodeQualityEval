/**https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/ */
//You are given two strings s and t consisting of only lowercase English letters.
//Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
// 
//Example 1:
//Input: s = "coaching", t = "coding"
//Output: 4
//Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
//Now, t is a subsequence of s ("coachingding").
//It can be shown that appending any 3 characters to the end of s will never make t a subsequence.
//Example 2:
//Input: s = "abcde", t = "a"
//Output: 0
//Explanation: t is already a subsequence of s ("abcde").
//Example 3:
//Input: s = "z", t = "abcde"
//Output: 5
//Explanation: Append the characters "abcde" to the end of s so that s = "zabcde".
//Now, t is a subsequence of s ("zabcde").
//It can be shown that appending any 4 characters to the end of s will never make t a subsequence.
// 
//Constraints:
//	1 <= s.length, t.length <= 105
//	s and t consist only of lowercase English letters.
class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j] + 1;
                }
            }
        }
        return dp[n][m];        
    }
};