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

    char** res = malloc(256 * sizeof(char*));
    *returnSize = 0;

    int count = 1 << n;
    for (int i = 0; i < count; i++) {
        char* str = malloc((n + 1) * sizeof(char));
        str[n] = '\0';  

        int j = 0;
        for (int k = 0; k < n; k++) {
            if ((i >> k) & 1) {
                str[j++] = '1';
            } else {
                str[j++] = '0';
            }
        }

        int isValid = 1;
        for (int k = 0; k < n - 1; k++) {
            if (str[k] == '1' && str[k + 1] == '1') {
                isValid = 0;
                break;
            }
        }

        if (isValid) {
            res[*returnSize] = str;
            (*returnSize)++;
        } else {
            free(str);
        }
    }
    return res; 
    
}