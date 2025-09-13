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
    int len = strlen(num);
    char** result = (char**)malloc(sizeof(char*) * 10000);
    *returnSize = 0;
    for (int i = 1; i <= len; i++) {
        long long value = atoll(num + i - 1);
        if (value == 0) {
            break;
        }
        char* expression = (char*)malloc(sizeof(char) * (2 * len + 1));
        sprintf(expression, "%lld", value);
        result[*returnSize] = expression;
        (*returnSize)++;
        if (i == len) {
            break;
        }
    }

    for (int i = 1; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            char* expression = (char*)malloc(sizeof(char) * (2 * len + 1));
            int expressionLen = 0;
            for (int k = 0; k < i; k++) {
                expression[expressionLen++] = num[k];
            }
            expression[expressionLen++] = '+';
            for (int k = i; k < j; k++) {
                expression[expressionLen++] = num[k];
            }
            expression[expressionLen] = '\0';
            result[*returnSize] = expression;
            (*returnSize)++;
            for (int k = j; k < len; k++) {
                char* expression = (char*)malloc(sizeof(char) * (2 * len + 1));
                int expressionLen = 0;
                for (int l = 0; l < i; l++) {
                    expression[expressionLen++] = num[l];
                }
                expression[expressionLen++] = '+';
                for (int l = i; l < j; l++) {
                    expression[expressionLen++] = num[l];
                }
                expression[expressionLen++] = '+';
                for (int l = j; l <= k; l++) {
                    expression[expressionLen++] = num[l];
                }
                expression[expressionLen] = '\0';
                result[*returnSize] = expression;
                (*returnSize)++;
            }
        }
    }
    return result;
    
}