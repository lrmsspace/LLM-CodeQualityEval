/**https://leetcode.com/problems/ambiguous-coordinates/ */
//We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)". Then, we removed all commas, decimal points, and spaces and ended up with the string s.
//	For example, "(1, 3)" becomes s = "(13)" and "(2, 0.5)" becomes s = "(205)".
//Return a list of strings representing all possibilities for what our original coordinates could have been.
//Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with fewer digits. Also, a decimal point within a number never occurs without at least one digit occurring before it, so we never started with numbers like ".1".
//The final answer list can be returned in any order. All coordinates in the final answer have exactly one space between them (occurring after the comma.)
// 
//Example 1:
//Input: s = "(123)"
//Output: ["(1, 2.3)","(1, 23)","(1.2, 3)","(12, 3)"]
//Example 2:
//Input: s = "(0123)"
//Output: ["(0, 1.23)","(0, 12.3)","(0, 123)","(0.1, 2.3)","(0.1, 23)","(0.12, 3)"]
//Explanation: 0.0, 00, 0001 or 00.01 are not allowed.
//Example 3:
//Input: s = "(00011)"
//Output: ["(0, 0.011)","(0.001, 1)"]
// 
//Constraints:
//	4 <= s.length <= 12
//	s[0] == '(' and s[s.length - 1] == ')'.
//	The rest of s are digits.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** ambiguousCoordinates(char* s, int* returnSize) {
    int len = strlen(s);
    int i, j, k;
    char* t1, *t2, *t3, *t4;
    char** res = (char**)malloc(len * len * sizeof(char*));
    int count = 0;

    for (i = 1; i < len - 1; ++i) {
        t1 = (char*)malloc((i + 1) * sizeof(char));
        t2 = (char*)malloc((len - i + 1) * sizeof(char));
        for (j = 0; j < i; ++j) t1[j] = s[j];
        t1[i] = '\0';
        for (k = 0; k < len - i; ++k) t2[k] = s[i + k];
        t2[len - i] = '\0';
        res[count++] = (char*)malloc(20 * sizeof(char));
        sprintf(res[count - 1], "(%s, %s)", t1, t2);
        free(t1);
        free(t2);
    }

    for (i = 1; i < len - 1; ++i) {
        t1 = (char*)malloc((i + 1) * sizeof(char));
        t2 = (char*)malloc((len - i + 1) * sizeof(char));
        for (j = 0; j < i; ++j) t1[j] = s[j];
        t1[i] = '\0';
        for (k = 0; k < len - i; ++k) t2[k] = s[i + k];
        t2[len - i] = '\0';
        res[count++] = (char*)malloc(20 * sizeof(char));
        sprintf(res[count - 1], "(%s.%s, %s)", t1, t2, t3);
        free(t1);
        free(t2);
    }

    *returnSize = count;
    return res;
}
