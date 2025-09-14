/**https://leetcode.com/problems/find-and-replace-pattern/ */
//Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
//A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
//Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.
// 
//Example 1:
//Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
//Output: ["mee","aqq"]
//Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
//"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
//Example 2:
//Input: words = ["a","b","c"], pattern = "a"
//Output: ["a","b","c"]
// 
//Constraints:
//	1 <= pattern.length <= 20
//	1 <= words.length <= 50
//	words[i].length == pattern.length
//	pattern and words[i] are lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findAndReplacePattern(char** words, int wordsSize, char* pattern, int* returnSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    char** result = (char**)malloc(1000 * sizeof(char*));
    *returnSize = 0;
    for(i = 0; i < wordsSize; i++) {
        int hash1[26] = {0};
        int hash2[26] = {0};
        int flag = 1;
        for(j = 0; j < strlen(words[i]); j++) {
            if(hash1[words[i][j] - 'a'] == 0 && hash2[pattern[j] - 'a'] == 0) {
                hash1[words[i][j] - 'a'] = pattern[j];
                hash2[pattern[j] - 'a'] = words[i][j];
            } else if(hash1[words[i][j] - 'a'] != pattern[j] || hash2[pattern[j] - 'a'] != words[i][j]) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            result[*returnSize] = (char*)malloc((strlen(words[i]) + 1) * sizeof(char));
            strcpy(result[*returnSize], words[i]);
            (*returnSize)++;
        }
    }
    return result;
}