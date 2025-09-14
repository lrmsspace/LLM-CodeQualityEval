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
char *** partition(char * s, int* returnSize, int** returnColumnSizes){
    int len = strlen(s);
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }
    int *dp = (int *)malloc(sizeof(int) * len * len);
    memset(dp, 0, sizeof(int) * len * len);
    for (int i = 0; i < len; i++) {
        dp[i * len + i] = 1;
    }
    for (int i = 0; i < len - 1; i++) {
        dp[i * len + i + 1] = s[i] == s[i + 1];
    }
    for (int i = 2; i < len; i++) {
        for (int j = 0; j < len - i; j++) {
            dp[j * len + i + j] = dp[(j + 1) * len + i + j - 1] && s[j] == s[i + j];
        }
    }
    int max = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (dp[i * len + j]) {
                max = max > j - i + 1 ? max : j - i + 1;
            }
        }
    }
    char ***res = (char ***)malloc(sizeof(char **) * max);
    memset(res, 0, sizeof(char **) * max);
    for (int i = 0; i < max; i++) {
        res[i] = (char **)malloc(sizeof(char *) * len);
        memset(res[i], 0, sizeof(char *) * len);
    }
    int *count = (int *)malloc(sizeof(int) * max);
    memset(count, 0, sizeof(int) * max);
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (dp[i * len + j]) {
                res[count[j - i + 1]][count[j - i + 1]] = (char *)malloc(sizeof(char) * (j - i + 2));
                memset(res[count[j - i + 1]][count[j - i + 1]], 0, sizeof(char));
            }
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (dp[i * len + j]) {
                strncpy(res[count[j - i + 1]][count[j - i + 1]], s + i, j - i + 1);
                count[j - i + 1]++;
            }
        }
    }
    *returnSize = max;
    *returnColumnSizes = (int *)malloc(sizeof(int) * max);
    memset(*returnColumnSizes, 0, sizeof(int) * max);
    for (int i = 0; i < max; i++) {
        (*returnColumnSizes)[i] = count[i];
    }
    free(dp);
    free(count);
    return res;
}