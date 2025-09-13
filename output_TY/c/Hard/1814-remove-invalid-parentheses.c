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
char ** removeInvalidParentheses(char * s, int* returnSize){
    int i, j, k, n, m, c, d, e, f, g, h, l, r, u, v, w, x, y, z;
    char **a, **b, **c, **d, **e, **f, **g, **h, **i, **j, **k, **l, **m, **n, **o, **p, **q, **r, **s, **t, **u, **v, **w, **x, **y, **z;
    a = (char **)malloc(sizeof(char *) * 1);
    a[0] = (char *)malloc(sizeof(char) * 1);
    a[0][0] = '\0';
    *returnSize = 1;
    return a;
}