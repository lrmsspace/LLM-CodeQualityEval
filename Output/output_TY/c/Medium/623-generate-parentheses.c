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
char ** generateParenthesis(int n, int* returnSize){
    int *left = (int *)malloc(sizeof(int) * n), *right = (int *)malloc(sizeof(int) * n);
    int left_size = 0, right_size = 0;
    char **ans = (char **)malloc(sizeof(char *) * 10000);
    int ans_size = 0;
    int i, j, k;
    for (i = 0; i < n;i++) {
        left[left_size++] = i;
    }
    while (left_size > 0) {
        int left_num = left[--left_size];
        int right_num = n - left_num - 1;
        char *str = (char *)malloc(sizeof(char) * (left_num + right_num + 1));
        for (i = 0; i < left_num; i++) {
            str[i] = '(';
        }
        for (i = left_num; i < left_num + right_num; i++) {
            str[i] = ')';
        }
    }
    str[left_num + right_num] = '\0';
    ans[ans_size++] = str;
    return ans;
}