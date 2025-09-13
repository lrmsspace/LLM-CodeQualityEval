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
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    char** result = (char**)malloc(sizeof(char*) * wordsSize);
    *returnSize = 0;
    for (i = 0; i < wordsSize; i++) {
        for (j = 0; j < wordsSize; j++) {
            if (j == i) continue;
            if (strstr(words[i], words[j]) != NULL) {
                result[*returnSize] = words[i];
                (*returnSize)++;
                break;
            }
        }
    }
    return result;
    
}