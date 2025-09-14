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
char* shortestSuperstring(char** words, int wordsSize) {
    int n = wordsSize;
    char* dp[1 << n];
    int dp_len[1 << n];
    char* res = NULL;
    int res_len = INT_MAX;

    for (int i = 0; i < 1 << n; i++) {
        dp[i] = (char*) malloc((n * 20 + 1) * sizeof(char));
        dp_len[i] = INT_MAX;
    }

    for (int i = 0; i < n; i++) {
        dp[1 << i][0] = '\0';
        strcat(dp[1 << i], words[i]);
        dp_len[1 << i] = strlen(words[i]);
    }

    for (int i = (1 << n) - 1; i >= 1; i--) {
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) continue;
            int k = i ^ (1 << j);
            if (dp_len[k] == INT_MAX) continue;
            for (int l = 0; l < n; l++) {
                if (l == j) continue;
                int len = strlen(words[j]) + dp_len[k];
                if (len < dp_len[i]) {
                    char* t = strstr(dp[k], words[j]);
                    if (t != dp[k]) {
                        int offset = strlen(words[j]) - (t - dp[k]);
                        if (offset < 0) offset = 0;
                        len -= offset;
                    }
                    dp_len[i] = len;
                    strcpy(dp[i], dp[k]);
                    strcat(dp[i], words[j] + strlen(words[j]) - (t - dp[k]));
                }
            }
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        if (dp_len[i] < res_len) {
            res_len = dp_len[i];
            if (res != NULL) free(res);
            res = strdup(dp[i]);
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        free(dp[i]);
    }

    return res;
}