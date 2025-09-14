/**https://leetcode.com/problems/find-the-shortest-superstring/ */
//Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.
//You may assume that no string in words is a substring of another string in words.
// 
//Example 1:
//Input: words = ["alex","loves","leetcode"]
//Output: "alexlovesleetcode"
//Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
//Example 2:
//Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
//Output: "gctaagttcatgcatc"
// 
//Constraints:
//	1 <= words.length <= 12
//	1 <= words[i].length <= 20
//	words[i] consists of lowercase English letters.
//	All the strings of words are unique.
char * shortestSuperstring(char ** words, int wordsSize){
        int n = wordsSize;
        int mask = 1 << n;
        int dp[mask][n];
        memset(dp, 0, sizeof(dp));
        int pre[mask][n];
        memset(pre, 0, sizeof(pre));
        int len[mask][n];
        memset(len, 0, sizeof(len));
        for (int i = 0; i < n; i++) {
            int m = strlen(words[i]);
            for (int j= 0; j < n; j++) {
                if (i == j) continue;
                int k = 0;
                while (k < m) {
                    int l = m - k;
                    char *s1 = words[i] + k;
                    char *s2 = words[j];
                    while (l >= 0 && strncmp(s1, s2, l) != 0) {
                        l--;
                    }
                    if (l >= 0) {
                        dp[1 << i][j] = m + len[1 << i][j];
                        pre[1 << i][j] = i;
                        len[1 << i][j] = m;
                    }
                }
            }
        }
        for (int i = 2; i < mask; i++) {
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) == 0) continue;
                for (int k = 0; k < n; k++) {
                    if (j == k || (i & (1 << k)) == 0) continue;
                    int m = strlen(words[k]);
                }
            }
        }
        return NULL;
}