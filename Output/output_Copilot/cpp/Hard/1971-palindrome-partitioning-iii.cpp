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
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int l = i, r = j, cnt = 0;
                while (l < r) {
                    if (s[l] != s[r]) cnt++;
                    l++, r--;
                }
                cost[i][j] = cnt;
            }
        }
        vector<vector<int>> dp(n, vector<int>(k + 1, 1000000));
        for (int i = 0; i < n; i++) {
            dp[i][1] = cost[0][i];
            for (int j = 2; j <= k; j++) {
                for (int l = 0; l < i; l++) {
                    dp[i][j] = min(dp[i][j], dp[l][j - 1] + cost[l + 1][i]);
                }
            }
        }
        return dp [n - 1][k];       
    }
};