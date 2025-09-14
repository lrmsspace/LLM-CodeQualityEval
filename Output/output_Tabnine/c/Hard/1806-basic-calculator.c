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
    stack<int> nums;
    stack<char> ops;
    
    int num = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] =='') continue;
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                char op = ops.top(); ops.pop();
                nums.push(applyOperation(a, b, op));
            }
            ops.push(s[i]);
            num = 0;
        }
    }
    
    while (!ops.empty()) {
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        nums.push(applyOperation(a, b, op));
    }
    
    return nums.top();
    
}