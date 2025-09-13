/**https://leetcode.com/problems/find-common-characters/ */
//Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
// 
//Example 1:
//Input: words = ["bella","label","roller"]
//Output: ["e","l","l"]
//Example 2:
//Input: words = ["cool","lock","cook"]
//Output: ["c","o"]
// 
//Constraints:
//	1 <= words.length <= 100
//	1 <= words[i].length <= 100
//	words[i] consists of lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** commonChars(char** words, int wordsSize, int* returnSize) {
    int* count = (int*)calloc(26, sizeof(int));
    int* minCount = (int*)calloc(26, sizeof(int));
    int* maxCount = (int*)calloc(26, sizeof(int));
    char** result = (char**)calloc(wordsSize, sizeof(char*));
    *returnSize = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < strlen(words[i]); j++) {
            count[words[i][j] - 'a']++;
        }
        if (i == 0) {
            memcpy(minCount, count, sizeof(int) * 26);
            memcpy(maxCount, count, sizeof(int) * 26);
        } else {
            for (int j = 0; j < 26; j++) {
                minCount[j] = fmin(minCount[j], count[j]);
                maxCount[j] = fmax(maxCount[j], count[j]);
            }
        }
    }
    
    for (int i = 0; i < 26; i++) {
        if (minCount[i] > 0) {
            result[*returnSize] = (char*)calloc(2, sizeof(char));
            result[*returnSize][0] = 'a' + i;
            result[*returnSize][1] = '\0';
            (*returnSize)++;
        }
    }
    
    free(count);
    free(minCount);
    free(maxCount);
    return result;
    
}