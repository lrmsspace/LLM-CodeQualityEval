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
    int n = strlen(s);
    char** result = malloc(sizeof(char*) * (pow(2, n) + 1));
    *returnSize = 0;
    
    // Initialize the first result with the original string
    result[0] = malloc(sizeof(char) * (n + 1));
    strcpy(result[0], s);
    (*returnSize)++;
    
    for (int i = 0; i < n; i++) {
        if (isalpha(s[i])) {
            int len = *returnSize;
            for (int j = 0; j < len; j++) {
                char* newStr = malloc(sizeof(char) * (n + 1));
                strcpy(newStr, result[j]);
                
                // Toggle the case of the current character
                if (islower(s[i])) {
                    newStr[i] = toupper(s[i]);
                } else {
                    newStr[i] = tolower(s[i]);
                }
                
                result[j] = newStr;
                result[(*returnSize)++] = newStr;
            }
        }
    }
    
    return result;
    
}