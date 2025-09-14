/**https://leetcode.com/problems/remove-invalid-parentheses/ */
//Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
//Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.
// 
//Example 1:
//Input: s = "()())()"
//Output: ["(())()","()()()"]
//Example 2:
//Input: s = "(a)())()"
//Output: ["(a())()","(a)()()"]
//Example 3:
//Input: s = ")("
//Output: [""]
// 
//Constraints:
//	1 <= s.length <= 25
//	s consists of lowercase English letters and parentheses '(' and ')'.
//	There will be at most 20 parentheses in s.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** removeInvalidParentheses(char* s, int* returnSize) {
    int n = strlen(s);
    int* stack = (int*)malloc(sizeof(int) * n);
    int top = 0;
    int* visited = (int*)calloc(n, sizeof(int));
    int* res = (int*)malloc(sizeof(int) * n);
    int resSize = 0;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            stack[top++] = i;
        } else if (s[i] == ')') {
            if (top == 0 || s[stack[top - 1]] == ')') {
                stack[top++] = i;
            } else {
                visited[stack[--top]] = 1;
            }
        }
    }
    
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == ')' && visited[i] == 0) {
            stack[top++] = i;
        } else if (s[i] == '(' && visited[i] == 1) {
            stack[top++] = i;
        } else {
            res[resSize++] = i;
        }
    }
    
    char** result = (char**)malloc(sizeof(char*) * (resSize + 1));
    for (int i = 0; i < resSize; ++i) {
        result[i] = (char*)malloc(sizeof(char) * (n - res[i] + 1));
        strncpy(result[i], s + res[i] + 1, n - res[i] - 1);
    }
    result[resSize] = NULL;
    
    *returnSize = resSize;
    free(stack);
    free(visited);
    return result;
}