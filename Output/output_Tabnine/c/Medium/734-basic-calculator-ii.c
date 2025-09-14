/**https://leetcode.com/problems/basic-calculator-ii/ */
//Given a string s which represents an expression, evaluate this expression and return its value. 
//The integer division should truncate toward zero.
//You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
//Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
// 
//Example 1:
//Input: s = "3+2*2"
//Output: 7
//Example 2:
//Input: s = " 3/2 "
//Output: 1
//Example 3:
//Input: s = " 3+5 / 2 "
//Output: 5
// 
//Constraints:
//	1 <= s.length <= 3 * 105
//	s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
//	s represents a valid expression.
//	All the integers in the expression are non-negative integers in the range [0, 231 - 1].
//	The answer is guaranteed to fit in a 32-bit integer.
int calculate(char* s) {
    stack<int> nums;
    stack<char> ops;
    
    int num = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] =='') continue;
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        } else {
            nums.push(num);
            num = 0;
            while (!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                char op = ops.top();
                ops.pop();
                nums.push(applyOp(a, b, op));
            }
            ops.push(s[i]);
        }
    }
    
    nums.push(num);
    
    while (!ops.empty()) {
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        nums.push(applyOp(a, b, op));
    }

    return nums.top();
    
}