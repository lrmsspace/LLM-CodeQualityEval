/**https://leetcode.com/problems/uncommon-words-from-two-sentences/ */
//A sentence is a string of single-space separated words where each word consists only of lowercase letters.
//A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
//Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.
// 
//Example 1:
//Input: s1 = "this apple is sweet", s2 = "this apple is sour"
//Output: ["sweet","sour"]
//Explanation:
//The word "sweet" appears only in s1, while the word "sour" appears only in s2.
//Example 2:
//Input: s1 = "apple apple", s2 = "banana"
//Output: ["banana"]
// 
//Constraints:
//	1 <= s1.length, s2.length <= 200
//	s1 and s2 consist of lowercase English letters and spaces.
//	s1 and s2 do not have leading or trailing spaces.
//	All the words in s1 and s2 are separated by a single space.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    char *s = (char *)malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(s, s1);
    strcat(s, " ");
    strcat(s, s2);
    char **res = (char **)malloc(sizeof(char *) * 100);
    *returnSize = 0;
    char *token = strtok(s, " ");
    while (token) {
        int i = 0;
        for (; i < *returnSize; i++) {
            if (strcmp(token, res[i]) == 0) {
                break;
            }
        }
        if (i == *returnSize) {
            res[(*returnSize)++] = token;
        } else {
            res[i] = "";
        }
        token = strtok(NULL, " ");
    }
    return res;    
}