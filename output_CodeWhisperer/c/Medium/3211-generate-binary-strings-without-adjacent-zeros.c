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
    int i, j, k;
    int count = 0;
    char** result = (char**)malloc(2 * n * sizeof(char*));
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2; j++) {
            result[count] = (char*)malloc((i + 1) * sizeof(char));
            for (k = 0; k < i; k++) {
                result[count][k] = '0' + j;
            }
            result[count][k] = '1';
            result[count][k + 1] = '\0';
            count++;
        }
    }
    *returnSize = count;
    return result;    
}