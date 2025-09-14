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


        #define MOD 1000000007

        int dp[501][51][2][2];

        int kmpBuild(char *evil, int *lps) {
            int m = strlen(evil);
            lps[0] = 0;
            int len = 0, i = 1;
            while (i < m) {
                if (evil[i] == evil[len]) {
                    len++;
                    lps[i] = len;
                    i++;
                } else {
                    if (len != 0) {
                        len = lps[len - 1];
                    } else {
                        lps[i] = 0;
                        i++;
                    }
                }
            }
            return m;
        }

        int dfs(int pos, int evilMatched, int tight1, int tight2, char *s1, char *s2, char *evil, int *lps) {
            if (evilMatched == strlen(evil)) return 0;
            if (pos == strlen(s1)) return 1;
            if (dp[pos][evilMatched][tight1][tight2] != -1) return dp[pos][evilMatched][tight1][tight2];

            int res = 0;
            char low = tight1 ? s1[pos] : 'a';
            char high = tight2 ? s2[pos] : 'z';

            for (char c = low; c <= high; c++) {
                int nextEvilMatched = evilMatched;
                while (nextEvilMatched > 0 && evil[nextEvilMatched] != c) {
                    nextEvilMatched = lps[nextEvilMatched - 1];
                }
                if (evil[nextEvilMatched] == c) nextEvilMatched++;

                res = (res + dfs(pos + 1, nextEvilMatched, tight1 && (c == low), tight2 && (c == high), s1, s2, evil, lps)) % MOD;
            }

            return dp[pos][evilMatched][tight1][tight2] = res;
        }

        int findGoodStrings(int n, char* s1, char* s2, char* evil) {
            int lps[51];
            memset(dp, -1, sizeof(dp));
            kmpBuild(evil, lps);
            return dfs(0, 0, 1, 1, s1, s2, evil, lps);
        }

            