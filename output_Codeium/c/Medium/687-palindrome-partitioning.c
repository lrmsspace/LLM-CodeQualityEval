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
bool isPalindrome(char* s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) {
            return false;
        }
    }
    return true;
}

void backtrack(char* s, int start, char**** result, int* returnSize, int*** returnColumnSizes, char*** currentPart, int* currentSize) {
    int length = strlen(s);
    if (start == length) {
        (*returnSize)++;
        *result = realloc(*result, (*returnSize) * sizeof(char**));
        *returnColumnSizes = realloc(*returnColumnSizes, (*returnSize) * sizeof(int*));
        (*returnColumnSizes)[*returnSize - 1] = malloc((*currentSize) * sizeof(int));
        (*result)[*returnSize - 1] = malloc((*currentSize) * sizeof(char*));
        for (int i = 0; i < *currentSize; i++) {
            (*returnColumnSizes)[*returnSize - 1][i] = strlen((*currentPart)[i]);
            (*result)[*returnSize - 1][i] = strdup((*currentPart)[i]);
        }
        return;
    }
    for (int end = start; end < length; end++) {
        if (isPalindrome(s, start, end)) {
            (*currentSize)++;
            *currentPart = realloc(*currentPart, (*currentSize) * sizeof(char*));
            (*currentPart)[*currentSize - 1] = strndup(s + start, end - start + 1);
            backtrack(s, end + 1, result, returnSize, returnColumnSizes, currentPart, currentSize);
            free((*currentPart)[*currentSize - 1]);
            (*currentSize)--;
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    char*** result = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    char** currentPart = NULL;
    int currentSize = 0;
    backtrack(s, 0, &result, returnSize, returnColumnSizes, &currentPart, &currentSize);
    return result;
}

    