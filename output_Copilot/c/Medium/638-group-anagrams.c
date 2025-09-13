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
    char ***res = (char ***)malloc(sizeof(char **) * strsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * strsSize);
    int *hash = (int *)malloc(sizeof(int) * strsSize);
    memset(hash, 0, sizeof(int) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        if (hash[i] == 1) {
            continue;
        }
        res[*returnSize] = (char **)malloc(sizeof(char *) * strsSize);
        (*returnColumnSizes)[*returnSize] = 0;
        res[*returnSize][(*returnColumnSizes)[*returnSize]] = strs[i];
        (*returnColumnSizes)[*returnSize]++;
        for (int j = i + 1; j < strsSize; j++) {
            if (hash[j] == 1) {
                continue;
            }
            if (strlen(strs[i]) != strlen(strs[j])) {
                continue;
            }
            int flag = 1;
            int *count = (int *)malloc(sizeof(int) * 26);
            memset(count, 0, sizeof(int) * 26);
            for (int k = 0; k < strlen(strs[i]); k++) {
                count[strs[i][k] - 'a']++;
                count[strs[j][k] - 'a']--;
            }
            for (int k = 0; k < 26; k++) {
                if (count[k] != 0) {
                    flag = 0;
                    break;
                }
            }
            free(count);
            if (flag == 1) {
                res[*returnSize][(*returnColumnSizes)[*returnSize]] = strs[j];
                (*returnColumnSizes)[*returnSize]++;
                hash[j] = 1;
            }
        }
        (*returnSize)++;
    }
    free(hash);
    return res;    
}