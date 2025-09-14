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
    int* minFreq = (int*)malloc(26 * sizeof(int));
    for (int i = 0; i < 26; i++) {
        minFreq[i] = INT_MAX;
    }

    for (int i = 0; i < wordsSize; i++) {
        int* freq = (int*)calloc(26, sizeof(int));
        for (char* p = words[i]; *p; p++) {
            freq[*p - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            if (freq[j] < minFreq[j]) {
                minFreq[j] = freq[j];
            }
        }
        free(freq);
    }

    char** result = (char**)malloc(wordsSize * 100 * sizeof(char*));
    int index = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < minFreq[i]; j++) {
            result[index] = (char*)malloc(2 * sizeof(char));
            result[index][0] = i + 'a';
            result[index][1] = '\0';
            index++;
        }
    }
    free(minFreq);
    *returnSize = index;
    return result;

}