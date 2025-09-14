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
char ** letterCasePermutation(char * s, int* returnSize){
    int n = strlen(s);
    *returnSize = 1 << n;
    char ** ans = (char **)malloc(sizeof(char *) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        ans[i] = (char *)malloc(sizeof(char) * (n + 1));
        ans[i][n] = '\0';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < *returnSize; j++) { 
            ans[j][i] = (j >> (n - 1 - i)) & 1 ? toupper(s[i]) : tolower(s[i]);
        }
    }   
    return ans;
}