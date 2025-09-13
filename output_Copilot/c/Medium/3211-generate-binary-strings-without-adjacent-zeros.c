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
    char** result = malloc(10000 * sizeof(char*));  // Allocate memory for the result
    *returnSize = 0;

    // Helper function to generate valid strings
    void generate(char* current, int index) {
        if (index == n) {
            result[(*returnSize)++] = strdup(current);
            return;
        }

        // Try adding '0' or '1' to the current string
        current[index] = '0';
        if (index < 2 || (current[index - 1] != '0' || current[index - 2] != '0')) {
            generate(current, index + 1);
        }

        current[index] = '1';
        if (index < 2 || (current[index - 1] != '1' || current[index - 2] != '1')) {
            generate(current, index + 1);
        }
    }

    char* current = malloc((n + 1) * sizeof(char));
    current[n] = '\0';
    generate(current, 0);
    free(current);

    return result;
}