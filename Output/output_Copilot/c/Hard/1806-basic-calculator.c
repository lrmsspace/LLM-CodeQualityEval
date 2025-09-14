/**https://leetcode.com/problems/basic-calculator/ */
//Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
//Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
// 
//Example 1:
//Input: s = "1 + 1"
//Output: 2
//Example 2:
//Input: s = " 2-1 + 2 "
//Output: 3
//Example 3:
//Input: s = "(1+(4+5+2)-3)+(6+8)"
//Output: 23
// 
//Constraints:
//	1 <= s.length <= 3 * 105
//	s consists of digits, '+', '-', '(', ')', and ' '.
//	s represents a valid expression.
//	'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
//	'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
//	There will be no two consecutive operators in the input.
//	Every number and running calculation will fit in a signed 32-bit integer.
int calculate(char* s) {
    int len = strlen(s);
    int *stack = (int *)malloc(sizeof(int) * len);
    int top = -1;
    int sign = 1;
    int result = 0;
    stack[++top] = sign;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            continue;
        } else if (s[i] == '+') {
            sign = stack[top];
        } else if (s[i] == '-') {
            sign = -stack[top];
        } else if (s[i] == '(') {
            stack[++top] = sign;
        } else if (s[i] == ')') {
            top--;
        } else {
            int num = 0;
            while (i < len && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
                i++;
            }
            i--;
            result += sign * num;
        }
    }
    return result;    
}