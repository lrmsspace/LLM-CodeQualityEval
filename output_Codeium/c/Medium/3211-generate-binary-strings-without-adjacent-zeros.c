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
    *returnSize = (1 << n) - (1 << (n - 1));
    char** result = (char**)malloc(*returnSize * sizeof(char*));
    int index = 0;
    for (int i = 0; i < (1 << n); i++) {
        char* str = (char*)malloc((n + 1) * sizeof(char));
        int j = n - 1;
        while (j >= 0) {
            str[j] = (i & 1) ? '1' : '0';
            i >>= 1;
            j--;
        }
        str[n] = '\0';
        bool valid = true;
        for (int k = 0; k < n - 1; k++) {
            if (str[k] == '0' && str[k + 1] == '0') {
                valid = false;
                break;
            }
        }
        if (valid) {
            result[index++] = str;
        }
    }
    return result;
}