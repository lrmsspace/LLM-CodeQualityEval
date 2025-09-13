/**https://leetcode.com/problems/remove-invalid-parentheses/ */
//Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
//Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.
// 
//Example 1:
//Input: s = "()())()"
//Output: ["(())()","()()()"]
//Example 2:
//Input: s = "(a)())()"
//Output: ["(a())()","(a)()()"]
//Example 3:
//Input: s = ")("
//Output: [""]
// 
//Constraints:
//	1 <= s.length <= 25
//	s consists of lowercase English letters and parentheses '(' and ')'.
//	There will be at most 20 parentheses in s.
/**
 * @param {string} s
 * @return {string[]}
 */
var removeInvalidParentheses = function(s) {
    let left = 0, right = 0, removeCount = 0;
    const stack = [];
    const result = [];
    
    // Count the number of parentheses and remove the minimum number of invalid ones
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            stack.push(i);
        } else if (s[i] === ')') {
            if (stack.length === 0) {
                removeCount++;
            } else {
                stack.pop();
            }
        }
    }
    
    // Remove the minimum number of invalid parentheses
    for (let i = s.length - 1; i >= 0 && removeCount > 0; i--) {
        if (s[i] === ')') {
            stack.push(i);
            removeCount--;
        } else if (s[i] === '(' && stack.length > 0) {
            stack.pop();
        }
    }
    
    // Construct the valid strings
    let valid = '';
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(' || s[i] === ')') {
            valid += s[i];
        } else if (stack.length > 0) {
            stack.pop();
        }
    }
    
    // Reverse the valid string and add it to the result
    let reversed = valid.split('').reverse().join('');
    result.push(reversed);
    
    return result;
    
};