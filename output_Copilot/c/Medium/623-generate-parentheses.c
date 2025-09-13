/**https://leetcode.com/problems/generate-parentheses/ */
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// 
//Example 1:
//Input: n = 3
//Output: ["((()))","(()())","(())()","()(())","()()()"]
//Example 2:
//Input: n = 1
//Output: ["()"]
// 
//Constraints:
//	1 <= n <= 8
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    char **result = (char **)malloc(sizeof(char *) * 10000);
    *returnSize = 0;
    char *temp = (char *)malloc(sizeof(char) * (2 * n + 1));
    temp[2 * n] = '\0';
    void generate(char *temp, int left, int right) {
        if (left == n && right == n) {
            result[(*returnSize)] = (char *)malloc(sizeof(char) * (2 * n + 1));
            strcpy(result[(*returnSize)++], temp);
            return;
        }
        if (left < n) {
            temp[left + right] = '(';
            generate(temp, left + 1, right);
        }
        if (right < left) {
            temp[left + right] = ')';
            generate(temp, left, right + 1);
        }
    }
    generate(temp, 0, 0);
    return result;    
}