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
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        if (n == k) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n - 1; i++) {
            dp[i][i + 1] = s[i] != s[i + 1];
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = dp[i + 1][j - 1] + (s[i] != s[j]);
            }
        }
        vector<int> dp2(n, 0);
        for (int i = 0; i < n; i++) {
            dp2[i] = INT_MAX;
            for (int j = 0; j <= i; j++) {
                dp2[i] = min(dp2[i], dp[j][i] + (j > 0 ? dp2[j - 1] : 0));
            }
        }
        return dp2[n - 1];
    }
};