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
class Solution {
    public int calculate(String s) {
        int n = s.length();
        int num = 0;
        int prevNum = 0;
        char prevOp = '+';
        Stack<Integer> stack = new Stack<>();
        
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            }
            if (!Character.isDigit(c) && c != ' ' || i == n - 1) {
                if (prevOp == '+') {
                    stack.push(num);
                } else if (prevOp == '-') {
                    stack.push(-num);
                } else if (prevOp == '*') {
                    prevNum = stack.pop();
                    stack.push(prevNum * num);
                } else if (prevOp == '/') {
                    prevNum = stack.pop();
                    stack.push(prevNum / num);
                }
                prevOp = c;
                num = 0;
            }
        }
        
        int result = 0;
        while (!stack.isEmpty()) {
            result += stack.pop();
        }
        
        return result;        
    }
}