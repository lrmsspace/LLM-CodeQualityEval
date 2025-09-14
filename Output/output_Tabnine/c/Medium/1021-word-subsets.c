/**https://leetcode.com/problems/word-subsets/ */
//You are given two string arrays words1 and words2.
//A string b is a subset of string a if every letter in b occurs in a including multiplicity.
//	For example, "wrr" is a subset of "warrior" but is not a subset of "world".
//A string a from words1 is universal if for every string b in words2, b is a subset of a.
//Return an array of all the universal strings in words1. You may return the answer in any order.
// 
//Example 1:
//Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
//Output: ["facebook","google","leetcode"]
//Example 2:
//Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
//Output: ["apple","google","leetcode"]
// 
//Constraints:
//	1 <= words1.length, words2.length <= 104
//	1 <= words1[i].length, words2[i].length <= 10
//	words1[i] and words2[i] consist only of lowercase English letters.
//	All the strings of words1 are unique.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize) {
    int* count1 = (int*)calloc(26, sizeof(int));
    int* count2 = (int*)calloc(26, sizeof(int));
    int* resultCount = (int*)calloc(26, sizeof(int));
    int* result = (int*)calloc(words1Size, sizeof(int));
    
    *returnSize = 0;
    
    for (int i = 0; i < words2Size; i++) {
        for (int j = 0; j < strlen(words2[i]); j++) {
            count2[words2[i][j] - 'a']++;
        }
    }
    
    for (int i = 0; i < words1Size; i++) {
        for (int j = 0; j < strlen(words1[i]); j++) {
            count1[words1[i][j] - 'a']++;
        }
        
        for (int j = 0; j < 26; j++) {
            resultCount[j] = fmin(count1[j], count2[j]);
        }
        
        int isUniversal = 1;
        for (int j = 0; j < 26; j++) {
            if (resultCount[j] < count2[j]) {
                isUniversal = 0;
                break;
            }
        }
        
        if (isUniversal) {
            result[*returnSize] = i;
            (*returnSize)++;
        }
        
        memset(count1, 0, sizeof(int) * 26);
    }

    char** resultArray = (char**)malloc(*returnSize * sizeof(char*));
    for (int i = 0; i < *returnSize; i++) {
        resultArray[i] = (char*)malloc((strlen(words1[result[i]]) + 1) * sizeof(char));
        strcpy(resultArray[i], words1[result[i]]);
    }
    
    free(count1);
    free(count2);
    free(resultCount);
    free(result);
    
    return resultArray;
    
}