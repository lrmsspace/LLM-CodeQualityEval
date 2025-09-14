/**https://leetcode.com/problems/split-array-into-fibonacci-sequence/ */
//You are given a string of digits num, such as "123456579". We can split it into a Fibonacci-like sequence [123, 456, 579].
//Formally, a Fibonacci-like sequence is a list f of non-negative integers such that:
//	0 <= f[i] < 231, (that is, each integer fits in a 32-bit signed integer type),
//	f.length >= 3, and
//	f[i] + f[i + 1] == f[i + 2] for all 0 <= i < f.length - 2.
//Note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.
//Return any Fibonacci-like sequence split from num, or return [] if it cannot be done.
// 
//Example 1:
//Input: num = "1101111"
//Output: [11,0,11,11]
//Explanation: The output [110, 1, 111] would also be accepted.
//Example 2:
//Input: num = "112358130"
//Output: []
//Explanation: The task is impossible.
//Example 3:
//Input: num = "0123"
//Output: []
//Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
// 
//Constraints:
//	1 <= num.length <= 200
//	num contains only digits.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* splitIntoFibonacci(char* num, int* returnSize) {
        
        // Check if a string is a valid number
        int isValidNumber(char* s) {
            if (s[0] == '0' && strlen(s) > 1) {
                return 0;
            }
            for (int i = 0; i < strlen(s); i++) {
                if (s[i] < '0' || s[i] > '9') {
                    return 0;
                }
            }
            return 1;
        }
        
        // Backtracking function to find a Fibonacci-like sequence
        void backtrack(char* num, int start, int end, int** result, int* returnSize, int* returnColumnSizes, int* path, int pathIndex) {
            if (start == end && pathIndex >= 3) {
                result[*returnSize] = (int*)malloc(pathIndex * sizeof(int));
                returnColumnSizes[*returnSize] = pathIndex;
                for (int i = 0; i < pathIndex; i++) {
                    result[*returnSize][i] = path[i];
                }
                (*returnSize)++;
                return;
            }
            for (int i = start; i < end; i++) {
                if (i > start && num[start] == '0') {
                    break;
                }
                char* s = (char*)malloc((i - start + 2) * sizeof(char));
                strncpy(s, num + start, i - start + 1);
                s[i - start + 1] = '\0';
                if (isValidNumber(s) && atoi(s) <= INT_MAX) {
                    int n = atoi(s);
                    if (pathIndex < 2 || n == path[pathIndex - 1] + path[pathIndex - 2]) {
                        path[pathIndex] = n;
                        backtrack(num, i + 1, end, result, returnSize, returnColumnSizes, path, pathIndex + 1);
                    }
                }
            }
        }
        
        // Initialize variables
        int n = strlen(num);
        int** result = (int**)malloc(1000 * sizeof(int*));
        int* pathLengths = (int*)malloc(1000 * sizeof(int));
        int* path = (int*)malloc(1000 * sizeof(int));
        *returnSize = 0;
        
        // Find a Fibonacci-like sequence
        backtrack(num, 0, n, result, returnSize, &pathLengths, path, 0);
        // Return result
        return result[0];
}