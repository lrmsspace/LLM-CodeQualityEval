/**https://leetcode.com/problems/palindrome-partitioning/ */
//Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
// 
//Example 1:
//Input: s = "aab"
//Output: [["a","a","b"],["aa","b"]]
//Example 2:
//Input: s = "a"
//Output: [["a"]]
// 
//Constraints:
//	1 <= s.length <= 16
//	s contains only lowercase English letters.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int n = strlen(s);
    int** dp = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])) {
                dp[j][i] = 1;
            }
        }
    }
    char*** ans = (char***)malloc(sizeof(char**) * 1000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;
    char* path = (char*)malloc(sizeof(char) * (n + 1));
    void dfs(int start, int n) {
        if (start == n) {
            ans[*returnSize] = (char**)malloc(sizeof(char*) * n);
            for (int i = 0; i < n; i++) {
                ans[*returnSize][i] = (char*)malloc(sizeof(char) * (strlen(path) + 1));
                strcpy(ans[*returnSize][i], path);
            }
            (*returnColumnSizes)[*returnSize] = n;
            (*returnSize)++;
            return;
        }
        for (int i = start; i < n; i++) {
            if (dp[start][i]) {
                int len = strlen(path);
                for (int j = 0; j < i - start + 1; j++) {
                    path[len + j] = s[start + j];
                }
                path[len + i - start + 1] = '\0';
                dfs(i + 1, n);
            }
        }
    }
    dfs(0, n);
    return ans;
}