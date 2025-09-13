/**https://leetcode.com/problems/group-anagrams/ */
//Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// 
//Example 1:
//Input: strs = ["eat","tea","tan","ate","nat","bat"]
//Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//Explanation:
//	There is no string in strs that can be rearranged to form "bat".
//	The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
//	The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
//Example 2:
//Input: strs = [""]
//Output: [[""]]
//Example 3:
//Input: strs = ["a"]
//Output: [["a"]]
// 
//Constraints:
//	1 <= strs.length <= 104
//	0 <= strs[i].length <= 100
//	strs[i] consists of lowercase English letters.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    char*** result = NULL;
    
    if (strsSize == 0) {
        return result;
    }
    
    int* count = (int*)malloc(strsSize * sizeof(int));
    memset(count, 0, strsSize * sizeof(int));
    
    char** sorted = (char**)malloc(strsSize * sizeof(char*));
    for (int i = 0; i < strsSize; i++) {
        int len = strlen(strs[i]);
        sorted[i] = (char*)malloc(len + 1);
        qsort(strs[i], len, sizeof(char), compare);
        strcpy(sorted[i], strs[i]);
    }
    
    for (int i = 0; i < strsSize; i++) {
        int found = 0;
        for (int j = 0; j < *returnSize; j++) {
            if (strcmp(sorted[i], sorted[count[j]]) == 0) {
                result[*returnSize - 1][count[j]++] = strs[i];
                (*returnColumnSizes)[*returnSize - 1]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            result = (char***)realloc(result, (*returnSize + 1) * sizeof(char**));
            result[*returnSize] = (char**)malloc(10 * sizeof(char*));
            result[*returnSize][count[*returnSize]++] = strs[i];
            (*returnColumnSizes) = (int*)realloc((*returnColumnSizes), (*returnSize + 1) * sizeof(int));
            (*returnColumnSizes)[*returnSize] = 1;
            (*returnSize)++;
        }
    }
    
    free(sorted);
    free(count);
    
    return result;
}