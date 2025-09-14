/**https://leetcode.com/problems/find-all-good-strings/ */
//Given the strings s1 and s2 of size n and the string evil, return the number of good strings.
//A good string has size n, it is alphabetically greater than or equal to s1, it is alphabetically smaller than or equal to s2, and it does not contain the string evil as a substring. Since the answer can be a huge number, return this modulo 109 + 7.
// 
//Example 1:
//Input: n = 2, s1 = "aa", s2 = "da", evil = "b"
//Output: 51 
//Explanation: There are 25 good strings starting with 'a': "aa","ac","ad",...,"az". Then there are 25 good strings starting with 'c': "ca","cc","cd",...,"cz" and finally there is one good string starting with 'd': "da". 
//Example 2:
//Input: n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet"
//Output: 0 
//Explanation: All strings greater than or equal to s1 and smaller than or equal to s2 start with the prefix "leet", therefore, there is not any good string.
//Example 3:
//Input: n = 2, s1 = "gx", s2 = "gz", evil = "x"
//Output: 2
// 
//Constraints:
//	s1.length == n
//	s2.length == n
//	s1 <= s2
//	1 <= n <= 500
//	1 <= evil.length <= 50
//	All strings consist of lowercase English letters.
class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) { 
        int mod = 1e9 + 7;

        int m = evil.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(m + 1, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= m; k++) {
                    int& ans = dp[i][j][k];
                    if (k == 0) {
                        ans = dp[i - 1][j][k];
                        if (j == 0) {
                            ans += (s1[i - 1] - 'a') * dp[i - 1][0][k];
                            ans %= mod;
                        }
                        if (j == 1) {
                            ans += (s2[i - 1] - 'a') *  dp[i - 1][1][k];
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                ans += dp[i][j][m];
                ans %= mod;
            }
        }
        return ans;
    }
};