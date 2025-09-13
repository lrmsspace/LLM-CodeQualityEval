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
char ** wordSubsets(char ** words1, int words1Size, char ** words2, int words2Size, int* returnSize){
    int i, j, k;
    int max_len = 0;
    for (i = 0; i < words2Size; i++) {
        int len = strlen(words2[i]);
        max_len = max(max_len, len);
    }
    int *cnt = malloc(sizeof(int) * 26);
    memset(cnt, 0, sizeof(int) * 26);
    for (i = 0; i < words2Size; i++) {
        int len = strlen(words2[i]);
        int *tmp = malloc(sizeof(int) * 26);
        memset(tmp, 0, sizeof(int) * 26);
        for (j = 0; j < len; j++) {
            tmp[words2[i][j] - 'a']++;
        }
        for(j = 0; j < 26; j++) {
            cnt[j] = cnt[j] > tmp[j] ? cnt[j] : tmp[j];
        }
    }
    for (i = 0; i < words1Size; i++) {
        int len = strlen(words1[i]);
        int *tmp = malloc(sizeof(int) * 26);
        memset(tmp, 0, sizeof(int) * 26);
        int flag = 1;
        for (j = 0; j < len; j++) {
            tmp[words1[i][j] - 'a']++;
        }
    }
    return ans;
}