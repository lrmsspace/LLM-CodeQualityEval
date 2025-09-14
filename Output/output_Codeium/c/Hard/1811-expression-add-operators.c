/**https://leetcode.com/problems/expression-add-operators/ */
//Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.
//Note that operands in the returned expressions should not contain leading zeros.
// 
//Example 1:
//Input: num = "123", target = 6
//Output: ["1*2*3","1+2+3"]
//Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
//Example 2:
//Input: num = "232", target = 8
//Output: ["2*3+2","2+3*2"]
//Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
//Example 3:
//Input: num = "3456237490", target = 9191
//Output: []
//Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
// 
//Constraints:
//	1 <= num.length <= 10
//	num consists of only digits.
//	-231 <= target <= 231 - 1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** addOperators(char* num, int target, int* returnSize) {
    int n = strlen(num);
    char *buf = malloc((n*3+1)*sizeof(char));
    char *p = buf;
    char **res = malloc(1000*sizeof(char*));
    int resCnt = 0;

    void dfs(int pos, long long val, long long last, int target, char *buf, char **res, int *resCnt) {
        if (pos == n) {
            if (val == target) {
                *resCnt = resCnt[0] + 1;
                res[resCnt[0]] = strdup(buf);
            }
            return;
        }
        for (int i = pos; i < n; i++) {
            if (i != pos && num[pos] == '0') break;
            long long cur = strtoll(num+pos, NULL, 10);
            if (pos == 0) {
                p += sprintf(p, "%lld", cur);
                dfs(i+1, cur, cur, target, buf, res, resCnt);
                p -= sprintf(p, "%lld", cur);
            } else {
                p += sprintf(p, "+%lld", cur);
                dfs(i+1, val+cur, cur, target, buf, res, resCnt);
                p -= sprintf(p, "+%lld", cur);

                p += sprintf(p, "-%lld", cur);
                dfs(i+1, val-cur, -cur, target, buf, res, resCnt);
                p -= sprintf(p, "-%lld", cur);

                p += sprintf(p, "*%lld", cur);
                dfs(i+1, val-last+last*cur, last*cur, target, buf, res, resCnt);
                p -= sprintf(p, "*%lld", cur);
            }
        }
    }
    dfs(0, 0, 0, target, buf, res, &resCnt);
    *returnSize = resCnt;
    return res;
}
