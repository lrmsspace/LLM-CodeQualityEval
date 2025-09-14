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
        
        // Check if a string is palindrome
        int isPalindrome(char* s, int start, int end) {
            while (start < end) {
                if (s[start++] != s[end--]) {
                    return 0;
                }
            }
            return 1;
        }
        
        // Backtracking function to find all palindrome partitions
        void backtrack(char* s, int start, int end, char*** result, int* returnSize, int** returnColumnSizes, char** path, int pathIndex) {
            if (start >= end) {
                result[*returnSize] = (char**)malloc(pathIndex * sizeof(char*));
                returnColumnSizes[0][*returnSize] = pathIndex;
                for (int i = 0; i < pathIndex; i++) {
                    result[*returnSize][i] = (char*)malloc((strlen(path[i]) + 1) * sizeof(char));
                    strcpy(result[*returnSize][i], path[i]);
                }
                (*returnSize)++;
                return;
            }
            for (int i = start; i < end; i++) {
                if (isPalindrome(s, start, i)) {
                    path[pathIndex] = (char*)malloc((i - start + 2) * sizeof(char));
                    strncpy(path[pathIndex], s + start, i - start + 1);
                    path[pathIndex][i - start + 1] = '\0';
                    backtrack(s, i + 1, end, result, returnSize, returnColumnSizes, path, pathIndex + 1);
                }
            }
        }
        
        // Initialize variables
        int n = strlen(s);
        char*** result = (char***)malloc(1000 * sizeof(char**));
        int* pathLengths = (int*)malloc(1000 * sizeof(int));
        char** path = (char**)malloc(1000 * sizeof(char*));
        *returnSize = 0;
        
        // Find all palindrome partitions
        backtrack(s, 0, n, result, returnSize, &pathLengths, path, 0);
        
        // Return result
        *returnColumnSizes = pathLengths;
        return result; 
}