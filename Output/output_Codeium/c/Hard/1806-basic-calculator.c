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
    int result = 0, sign = 1, num = 0, i = 0;
    while (i < strlen(s)) {
        if (s[i] == ' ') {
            i++;
            continue;
        }
        if (s[i] == '(') {
            int j = i + 1;
            int count = 1;
            while (count != 0) {
                if (s[j] == '(') {
                    count++;
                } else if (s[j] == ')') {
                    count--;
                }
                j++;
            }
            int temp = calculate(strndup(s + i + 1, j - i - 2));
            result += sign * temp;
            i = j;
        } else if (s[i] == ')') {
            return result;
        } else if (s[i] == '+') {
            sign = 1;
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        } else {
            num = 0;
            while (i < strlen(s) && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            result += sign * num;
        }
    }
    return result;
}
