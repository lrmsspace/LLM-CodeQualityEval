/**https://leetcode.com/problems/letter-case-permutation/ */
//Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
//Return a list of all possible strings we could create. Return the output in any order.
// 
//Example 1:
//Input: s = "a1b2"
//Output: ["a1b2","a1B2","A1b2","A1B2"]
//Example 2:
//Input: s = "3z4"
//Output: ["3z4","3Z4"]
// 
//Constraints:
//	1 <= s.length <= 12
//	s consists of lowercase English letters, uppercase English letters, and digits.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCasePermutation(char* s, int* returnSize) {
    int len = strlen(s);
    int count = 1;
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            count *= 2;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            count *= 2;
        }
    }
    char** result = (char**)malloc(sizeof(char*) * count);
    for (int i = 0; i < count; i++) {
        result[i] = (char*)malloc(sizeof(char) * (len + 1));
    }
    *returnSize = count;
    int index = 0;
    for (int i = 0; i < count; i++) {
        int j = 0;
        for (j = 0; j < len; j++) {
            if (s[j] >= 'a' && s[j] <= 'z') {
                result[i][j] = (i & (1 << index)) ? s[j] - 32 : s[j];
                index++;
            } else if (s[j] >= 'A' && s[j] <= 'Z') {
                result[i][j] = (i & (1 << index)) ? s[j] : s[j] + 32;
                index++;
            } else {
                result[i][j] = s[j];
            }
        }
        result[i][j] = '\0';
        index = 0;
    }
    return result;
}