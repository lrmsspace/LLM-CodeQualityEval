/*
 You are given a positive integer n.
 A binary string x is valid if all substrings of x of length 2 contain at least one "1".
 Return all valid strings with length n, in any order.
 Example 1:
 Input: n = 3
 Output: ["010","011","101","110","111"]
 Explanation:
 The valid strings of length 3 are: "010", "011", "101", "110", and "111".
 Example 2:
 Input: n = 1
 Output: ["0","1"]
 Explanation:
 The valid strings of length 1 are: "0" and "1".
 Constraints:
 1 <= n <= 18
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** validStrings(int n, int* returnSize) {
    *returnSize = 0;
    char **res = malloc(sizeof(char*) * (1 << n));
    for (int i = 0; i < (1 << n); i++) {
        char *s = malloc(sizeof(char) * (n + 1));
        s[n] = '\0';
        for (int j = 0; j < n; j++) {
            s[j] = (i & (1 << j)) ? '1' : '0';
        }
        if (s[0] != '0' && s[n - 1] != '0') {
            res[(*returnSize)++] = s;
        } else {
            free(s);
        }
    }
    return res; 
    
}