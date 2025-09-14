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
    let dfs = (str, left, right) => {
        if (left === 0 && right === 0) {
            result.push(str);
            return;
        }
        if (left > 0) {
            dfs(str + '(', left - 1, right);
        }
        if (right > left) {
            dfs(str + ')', left, right - 1);
        }
    }
    dfs('', n, n);
    return result; 
};