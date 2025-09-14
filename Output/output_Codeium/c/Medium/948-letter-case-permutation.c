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


void dfs(char* s, int cur, int len, char** res, int* idx) {
    if (cur == len) {
        res[(*idx)++] = strdup(s);
        return;
    }
    dfs(s, cur + 1, len, res, idx);
    if (isalpha(s[cur])) {
        s[cur] ^= (1 << 5);
        dfs(s, cur + 1, len, res, idx);
        s[cur] ^= (1 << 5);
    }
}
char** letterCasePermutation(char* s, int* returnSize) {
    
    int len = strlen(s);
    char** res = (char**)malloc(1 << len * sizeof(char*));
    int idx = 0;
    dfs(s, 0, len, res, &idx);
    *returnSize = idx;
    return res;
}   