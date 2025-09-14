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
class Solution {
    public int calculate(String s) {
        int n = s.length();
        Deque<Integer> stack = new ArrayDeque<>();
        int num = 0;
        char sign = '+';
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+' || c == '-' || c == '(' || c == ')') {
                if (sign == '-') {
                    stack.push(-num);
                } else {
                    stack.push(num);
                }
                sign = c;
                num = 0;
            } else if (c =='') {
                continue;
            }
        }
        if (sign == '-') {
            stack.push(-num);
        } else {
            stack.push(num);
        }
        int result = 0;
        while (!stack.isEmpty()) {
            int temp = stack.pop();
            if (!stack.isEmpty()) {
                char operator = stack.pop();
                if (operator == '+') {
                    result += temp;
                } else {
                    result -= temp;
                }
            } else {
                result = temp;
            }
        }
        return result;
        
    }
}