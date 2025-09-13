/**https://leetcode.com/problems/valid-parenthesis-string/ */
//Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
//The following rules define a valid string:
//	Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//	Any right parenthesis ')' must have a corresponding left parenthesis '('.
//	Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//	'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
// 
//Example 1:
//Input: s = "()"
//Output: true
//Example 2:
//Input: s = "(*)"
//Output: true
//Example 3:
//Input: s = "(*))"
//Output: true
// 
//Constraints:
//	1 <= s.length <= 100
//	s[i] is '(', ')' or '*'.
/**
 * @param {string} s
 * @return {boolean}
 */
var checkValidString = function(s) {
    let stack = [];
    let minCount = 0;
    
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            stack.push(i);
        } else if (s[i] === ')') {
            if (stack.length === 0) {
                if (s[i - 1] === '*') minCount++;
                else return false;
            } else {
                stack.pop();
            }
        } else {
            if (stack.length === 0) minCount++;
            else stack.pop();
        }
    }
    
    while (stack.length > 0 && minCount > 0) {
        stack.pop();
        minCount--;
    }
    
    return stack.length === 0;
    
};