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
        int overlap[12][12] = {0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    for (int k = 1; k < strlen(words[i]); k++) {
                        if (strncmp(words[j], words[i] + strlen(words[i]) - k, k) == 0) {
                            overlap[i][j] = k;
                        }
                    }
                }
            }
        }
        int dp[1 << 12][12] = {0};
        int parent[1 << 12][12] = {0};
        for (int i = 0; i < 1 << n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = INT_MAX;
            }
        }
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = strlen(words[i]);
        }
        for (int i = 1; i < 1 << n; i++) {
            for (int j = 0; j < n; j++) {
                if (i & 1 << j) {
                    for (int k = 0; k < n; k++) {
                        if (i & 1 << k) {
                            if (dp[i ^ 1 << j][k] + strlen(words[j]) - overlap[k][j] < dp[i][j]) {
                                dp[i][j] = dp[i ^ 1 << j][k] + strlen(words[j]) - overlap[k][j];
                                parent[i][j] = k;
                            }
                        }
                    }
                }
            }
        }
        int min = INT_MAX, start = 0;
        for (int i = 0; i < n; i++) {
            if (dp[(1 << n) - 1][i] < min) {
                min = dp[(1 << n) - 1][i];
                start = i;
            }
        }
        char* result = (char*)malloc(100 * sizeof(char));
        int resultSize = 0;
        int mask = (1 << n) - 1;
        while (mask) {
            int next = parent[mask][start];
            if (mask == 1 << start) {
                for (int i = 0; i < strlen(words[start]); i++) {
                    result[resultSize++] = words[start][i];
                }
            } else {
                for (int i = strlen(words[start]) - overlap[next][start]; i < strlen(words[start]); i++) {
                    result[resultSize++] = words[start][i];
                }
            }
            mask ^= 1 << start;
            start = next;
        }
        result[resultSize] = '\0';
        return result;     
}