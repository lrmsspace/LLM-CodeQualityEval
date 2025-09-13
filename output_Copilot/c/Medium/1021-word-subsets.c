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
    int *max = (int *)malloc(sizeof(int) * 26);
    memset(max, 0, sizeof(int) * 26);
    for (int i = 0; i < words2Size; i++) {
        int *count = (int *)malloc(sizeof(int) * 26);
        memset(count, 0, sizeof(int) * 26);
        for (int j = 0; words2[i][j] != '\0'; j++) {
            count[words2[i][j] - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            max[j] = max[j] > count[j] ? max[j] : count[j];
        }
    }
    char **result = (char **)malloc(sizeof(char *) * words1Size);
    *returnSize = 0;
    for (int i = 0; i < words1Size; i++) {
        int *count = (int *)malloc(sizeof(int) * 26);
        memset(count, 0, sizeof(int) * 26);
        for (int j = 0; words1[i][j] != '\0'; j++) {
            count[words1[i][j] - 'a']++;
        }
        int j = 0;
        for (; j < 26; j++) {
            if (count[j] < max[j]) {
                break;
            }
        }
        if (j == 26) {
            result[(*returnSize)++] = words1[i];
        }
    }
    return result;    
}