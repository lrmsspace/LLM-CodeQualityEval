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
    int i, j;
    for (i = 0; i < strlen(words[0]); i++) {
        count[words[0][i] - 'a']++;
    }
    for (i = 1; i < wordsSize; i++) {
        int* temp = (int*)calloc(26, sizeof(int));
        for (j = 0; j < strlen(words[i]); j++) {
            temp[words[i][j] - 'a']++;
        }
        for (j = 0; j < 26; j++) {
            count[j] = count[j] < temp[j] ? count[j] : temp[j];
        }
        free(temp);
    }
    char** result = (char**)malloc(sizeof(char*) * 100);
    int k = 0;
    for (i = 0; i < 26; i++) {
        for (j = 0; j < count[i]; j++) {
            result[k] = (char*)malloc(sizeof(char) * 2);
            result[k][0] = i + 'a';
            result[k][1] = '\0';
            k++;
        }
    }
    *returnSize = k;
    free(count);
    return result;
    
}