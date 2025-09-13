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
int findGoodStrings(int n, char* s1, char* s2, char* evil) {
    int mod = 1000000007;
    int dp[501][51][2][2] = {0};
    int l = strlen(evil);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < 2; k++) {
                for (int m = 0; m < 2; m++) {
                    dp[i][j][k][m] = -1;
                }
            }
        }
    }
    int dfs(int i, int j, int k, int m) {
        if (j == l) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        if (dp[i][j][k][m] != -1) {
            return dp[i][j][j][m];
        }
        int res = 0;
        for (int c = (k ? s1[i] : 'a'); c <= (m ? s2[i] : 'z'); c++) {
            int j2 = j;
            while (j2 > 0 && evil[j2] != c) {
                j2 = dp[i][j2 - 1][k][m];
            }
            if (c == evil[j2]) {
                j2++;
            }
            res += dfs(i + 1, j2, k && c == s1[i], m && c == s2[i]);
            res %= mod;
        }
        dp[i][j][k][m] = res;
        return res;
    }
    return dfs(0, 0, 1, 1);
}