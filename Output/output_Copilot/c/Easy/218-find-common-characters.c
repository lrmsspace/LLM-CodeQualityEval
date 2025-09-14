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
    int *minFreq = (int *)malloc(sizeof(int) * 26);
    memset(minFreq, 0x3f, sizeof(int) * 26);
    for (int i = 0; i < wordsSize; i++) {
        int freq[26] = {0};
        for (int j = 0; j < strlen(words[i]); j++) {
            freq[words[i][j] - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            minFreq[j] = fmin(minFreq[j], freq[j]);
        }
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
        count += minFreq[i];
    }
    char **ret = (char **)malloc(sizeof(char *) * count);
    for (int i = 0; i < count; i++) {
        ret[i] = (char *)malloc(sizeof(char) * 2);
        ret[i][0] = i + 'a';
        ret[i][1] = '\0';
    }
    *returnSize = count;
    return ret;    
}