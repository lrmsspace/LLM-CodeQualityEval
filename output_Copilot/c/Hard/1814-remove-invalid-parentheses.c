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
    char** res = (char**)malloc(sizeof(char*) * 1000);
    int resSize = 0;
    *returnSize = 0;
    int left = 0, right = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            left++;
        } else if (s[i] == ')') {
            if (left > 0) {
                left--;
            } else {
                right++;
            }
        }
    }
    int* visited = (int*)malloc(sizeof(int) * 1000);
    for (int i = 0; i < 1000; i++) {
        visited[i] = 0;
    }
    char* path = (char*)malloc(sizeof(char) * 1000);
    removeInvalidParenthesesDFS(s, 0, 0, 0, left, right, visited, path, res, &resSize);
    *returnSize = resSize;
    return res;    
}