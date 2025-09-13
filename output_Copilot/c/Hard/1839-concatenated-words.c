/**https://leetcode.com/problems/concatenated-words/ */
//Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
//A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necessarily distinct) in the given array.
// 
//Example 1:
//Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
//Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
//Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
//"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
//"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
//Example 2:
//Input: words = ["cat","dog","catdog"]
//Output: ["catdog"]
// 
//Constraints:
//	1 <= words.length <= 104
//	1 <= words[i].length <= 30
//	words[i] consists of only lowercase English letters.
//	All the strings of words are unique.
//	1 <= sum(words[i].length) <= 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findAllConcatenatedWordsInADict(char** words, int wordsSize, int* returnSize) {
       *returnSize = 0;
        int* wordLengths = (int*)malloc(wordsSize * sizeof(int));
        for (int i = 0; i < wordsSize; i++) {
            wordLengths[i] = strlen(words[i]);
        }
        int** trie = (int**)malloc(26 * sizeof(int*));
        for (int i = 0; i < 26; i++) {
            trie[i] = NULL;
        }
        for (int i = 0; i < wordsSize; i++) {
            int len = wordLengths[i];
            int** node = trie;
            for (int j = 0; j < len; j++) {
                int index = words[i][j] - 'a';
                if (node[index] == NULL) {
                    node[index] = (int*)malloc(27 * sizeof(int));
                    for (int k = 0; k < 26; k++) {
                        node[index][k] = 0;
                    }
                    node[index][26] = 0;
                }
                node = (int**)node[index];
            }
            node[26] = i + 1;
        }
        char** result = (char**)malloc(10000 * sizeof(char*));
        for (int i = 0; i < wordsSize; i++) {
            int len = wordLengths[i];
            if (len == 0) {
                continue;
            }
            int* dp = (int*)malloc((len + 1) * sizeof(int));
            dp[0] = 1;
            for (int j = 0; j < len; j++) {
                if (dp[j] == 0) {
                    continue;
                }
                int** node = trie;
                for (int k = j; k < len; k++) {
                    int index = words[i][k] - 'a';
                    if (node[index] == NULL) {
                        break;
                    }
                    node = (int**)node[index];
                    if (node[26] > 0 && node[26] != i + 1) {
                        dp[k + 1] = 1;
                    }
                }
                if (dp[len] == 1) {
                    result[*returnSize] = (char*)malloc((len + 1) * sizeof(char));
                    strcpy(result[*returnSize], words[i]);
                    (*returnSize)++;
                    break;
                }
            }
            free(dp);
        }
        free(wordLengths);
        for (int i = 0; i < 26; i++) {
            if (trie[i] != NULL) {
                free(trie[i]);
            }
        }
        free(trie);
        return result;  
}