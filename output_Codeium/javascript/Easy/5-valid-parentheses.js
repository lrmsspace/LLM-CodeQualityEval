/**https://leetcode.com/problems/valid-parentheses/ */
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//An input string is valid if:
//	Open brackets must be closed by the same type of brackets.
//	Open brackets must be closed in the correct order.
//	Every close bracket has a corresponding open bracket of the same type.
// 
//Example 1:
//Input: s = "()"
//Output: true
//Example 2:
//Input: s = "()[]{}"
//Output: true
//Example 3:
//Input: s = "(]"
//Output: false
//Example 4:
//Input: s = "([])"
//Output: true
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of parentheses only '()[]{}'.
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let stack = [];
    for (let i = 0; i < s.length; i++) {
        let c = s[i];
        if (c === '(') {
            stack.push(')');
        } else if (c === '{') {
            stack.push('}');
        } else if (c === '[') {
            stack.push(']');
        } else if (stack.length === 0 || stack.pop() !== c) {
            return false;
        }
    }
    return stack.length === 0;
};