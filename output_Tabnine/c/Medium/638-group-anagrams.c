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
    int* count = malloc(26 * sizeof(int));
    int* index = malloc(strsSize * sizeof(int));
    memset(count, 0, 26 * sizeof(int));
    memset(index, -1, strsSize * sizeof(int));
    
    for (int i = 0; i < strsSize; i++) {
        int sum = 0;
        for (int j = 0; strs[i][j]; j++) {
            sum += strs[i][j] - 'a';
        }
        count[sum]++;
    }
    
    int groupSize = 0;
    for (int i = 0; i < 26; i++) {
        groupSize += count[i];
    }
    
    *returnSize = groupSize;
    *returnColumnSizes = malloc(groupSize * sizeof(int));
    int column = 0;
    char*** groups = malloc(groupSize * sizeof(char**));
    for (int i = 0; i < 26; i++) {
        (*returnColumnSizes)[column] = count[i];
        if (count[i] > 0) {
            groups[column] = malloc(count[i] * sizeof(char*));
            for (int j = 0; j < count[i]; j++) {
                int k = index[i * count[i] + j];
                groups[column][j] = malloc((strlen(strs[k]) + 1) * sizeof(char));
                strcpy(groups[column][j], strs[k]);
            }
            column++;
        }
    }
    
    free(count);
    free(index);
    
    return groups;
    
}