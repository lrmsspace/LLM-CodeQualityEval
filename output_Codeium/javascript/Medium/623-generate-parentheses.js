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
    function generate(A = [], left = 0, right = 0) {
        if (A.length == 2 * n) {
            result.push(A.join(''));
            return;
        }
        if (left < n) generate(A.concat('('), left + 1, right);
        if (right < left) generate(A.concat(')'), left, right + 1);
    }
    generate();
    return result;
};