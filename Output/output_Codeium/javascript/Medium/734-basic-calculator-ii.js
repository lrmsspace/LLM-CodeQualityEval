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
/**
 * @param {string} s
 * @return {number}
 */
var calculate = function(s) {
    let num = 0;
    let sign = 1;
    let result = 0;
    let stack = [];
    for (let i = 0; i < s.length; i++) {
        if (s[i] === ' ') continue;
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + parseInt(s[i]);
        } else if (s[i] === '+' || s[i] === '-') {
            result += sign * num;
            num = 0;
            sign = s[i] === '+' ? 1 : -1;
        } else if (s[i] === '(') {
            stack.push(result);
            stack.push(sign);
            sign = 1;
            result = 0;
        } else if (s[i] === ')') {
            result += sign * num;
            num = 0;
            result *= stack.pop();
            result += stack.pop();
        }
    }
    result += sign * num;
    return result;
};