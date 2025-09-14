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
    const stack = [];
    let num = 0;
    let sign = 1;
    let i = 0;
    
    while (i < s.length) {
        if (s[i] ==='') {
            i++;
            continue;
        }
        
        if (s[i] === '+' || s[i] === '-') {
            stack.push(num * sign);
            num = 0;
            sign = s[i] === '+'? 1 : -1;
            i++;
            continue;
        }
        
        if (s[i] === '*' || s[i] === '/') {
            stack.push(num * sign);
            num = 0;
            let op = s[i];
            i++;
            while (i < s.length && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            sign = op === '*'? stack.pop() : Math.floor(stack.pop() / num);
        }
        
        while (i < s.length && s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
            i++;
        }
    
    
        if (i < s.length && (s[i] === '+' || s[i] === '-')) {
            break;
        }
    }
    
    stack.push(num * sign);
    
    return stack.reduce((acc, curr) => acc + curr, 0);
    
};