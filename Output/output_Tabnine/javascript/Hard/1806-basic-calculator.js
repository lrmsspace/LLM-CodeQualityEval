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
/**
 * @param {string} s
 * @return {number}
 */
var calculate = function(s) {
    const stack = [];
    let num = 0;
    let sign = '+';
    let result = 0;
    
    for (let i = 0; i < s.length; i++) {
        if (s[i] ==='') continue;
        
        if (Number.isInteger(parseInt(s[i]))) {
            num = num * 10 + parseInt(s[i]);
        } else {
            result += sign === '+'? num : -num;
            num = 0;
            sign = s[i];
        }
        
        if (i === s.length - 1) {
            result += sign === '+'? num : -num;
        }
    }
    
    return result;
    
};