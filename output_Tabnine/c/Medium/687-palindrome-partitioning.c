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
    *returnSize = 0;
    *returnColumnSizes = malloc(n * sizeof(int));
    
    char*** res = malloc(n * sizeof(char**));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = 0;
        res[i] = malloc(n * sizeof(char*));
    }
    
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = 1;
        res[i][0] = malloc((i + 1) * sizeof(char));
        res[i][0][0] = s[i];
    }
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && (len == 2 || res[i + 1][j - 1])) {
                (*returnColumnSizes)[i] = (*returnColumnSizes)[i] + 1;
                res[i] = realloc(res[i], (*returnColumnSizes)[i] * sizeof(char*));
                res[i][(*returnColumnSizes)[i] - 1] = malloc((j - i + 1) * sizeof(char));
                memcpy(res[i][(*returnColumnSizes)[i] - 1], s + i, j - i + 1);
            }
        }
    }
    
    *returnSize = n;
    return res;
    
}