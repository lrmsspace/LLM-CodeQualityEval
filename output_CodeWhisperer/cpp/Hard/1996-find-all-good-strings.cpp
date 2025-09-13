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
        int dp[501][2][51];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, int)> dfs = [&](int i, int eq1, int eq2) {
            if (dp[i][eq1][eq2] != -1) return dp[i][eq1][eq2];
            if (i == n) return 1;
            int res = 0;
            char from = (eq1 == 1 ? s1[i] : 'a'), to = (eq2 == 1 ? s2[i] : 'z');
            for (char c = from; c <= to; c++) {
                int j = 0;
                while (j < evil.size() && evil[j] != c) j++;
                int neq1 = eq1, neq2 = eq2;
                if (c != s1[i]) neq1 = 0;
                if (c != s2[i]) neq2 = 0;
                if (j == evil.size()) res = (res + dfs(i + 1, neq1, neq2)) % mod;
            }
            return dp[i][eq1][eq2] = res;
        };
        return dfs(0, 1, 1);       
    }
};