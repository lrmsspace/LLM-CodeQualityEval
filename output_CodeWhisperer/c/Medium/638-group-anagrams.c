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
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    char*** result = (char***)malloc(sizeof(char**) * strsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    *returnSize = 0;
    for (i = 0; i < strsSize; i++) {
        for (j = i + 1; j < strsSize; j++) {
            if (strcmp(strs[i], strs[j]) > 0) {
                char* temp = strs[i];
                strs[i] = strs[j];
                strs[j] = temp;
            }
        }
    }
    for (i = 0; i < strsSize; i++) {
        if (i == 0 || strcmp(strs[i], strs[i - 1]) != 0) {
            result[*returnSize] = (char**)malloc(sizeof(char*) * strsSize);
            (*returnColumnSizes)[*returnSize] = 0;
            for (j = i; j < strsSize; j++) {
                if (strcmp(strs[i], strs[j]) == 0) {
                    result[*returnSize][(*returnColumnSizes)[*returnSize]] = (char*)malloc(sizeof(char) * (strlen(strs[j]) + 1));
                    strcpy(result[*returnSize][(*returnColumnSizes)[*returnSize]], strs[j]);
                    (*returnColumnSizes)[*returnSize]++;
                }
            }
            (*returnSize)++;
        }
    }
    return result;
}