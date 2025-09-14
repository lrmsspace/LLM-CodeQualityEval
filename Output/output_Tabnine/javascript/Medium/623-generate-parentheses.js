/**https://leetcode.com/problems/generate-parentheses/ */
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// 
//Example 1:
//Input: n = 3
//Output: ["((()))","(()())","(())()","()(())","()()()"]
//Example 2:
//Input: n = 1
//Output: ["()"]
// 
//Constraints:
//	1 <= n <= 8
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let result = [];
    let helper = (left, right, str) => {
        if (left === 0 && right === 0) {
            result.push(str);
            return;
        }
        if (left > 0) {
            helper(left - 1, right, str + '(');
        }
        if (right > left) {
            helper(left, right - 1, str + ')');
        }
    }
    helper(n, n, '');
    return result;
    
};