/**https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/ */
//You are given a valid boolean expression as a string expression consisting of the characters '1','0','&' (bitwise AND operator),'|' (bitwise OR operator),'(', and ')'.
//	For example, "()1|1" and "(1)&()" are not valid while "1", "(((1))|(0))", and "1|(0&(1))" are valid expressions.
//Return the minimum cost to change the final value of the expression.
//	For example, if expression = "1|1|(0&0)&1", its value is 1|1|(0&0)&1 = 1|1|0&1 = 1|0&1 = 1&1 = 1. We want to apply operations so that the new expression evaluates to 0.
//The cost of changing the final value of an expression is the number of operations performed on the expression. The types of operations are described as follows:
//	Turn a '1' into a '0'.
//	Turn a '0' into a '1'.
//	Turn a '&' into a '|'.
//	Turn a '|' into a '&'.
//Note: '&' does not take precedence over '|' in the order of calculation. Evaluate parentheses first, then in left-to-right order.
// 
//Example 1:
//Input: expression = "1&(0|1)"
//Output: 1
//Explanation: We can turn "1&(0|1)" into "1&(0&1)" by changing the '|' to a '&' using 1 operation.
//The new expression evaluates to 0. 
//Example 2:
//Input: expression = "(0&0)&(0&0&0)"
//Output: 3
//Explanation: We can turn "(0&0)&(0&0&0)" into "(0|1)|(0&0&0)" using 3 operations.
//The new expression evaluates to 1.
//Example 3:
//Input: expression = "(0|(1|0&1))"
//Output: 1
//Explanation: We can turn "(0|(1|0&1))" into "(0|(0|0&1))" using 1 operation.
//The new expression evaluates to 0.
// 
//Constraints:
//	1 <= expression.length <= 105
//	expression only contains '1','0','&','|','(', and ')'
//	All parentheses are properly matched.
//	There will be no empty parentheses (i.e: "()" is not a substring of expression).
/**
 * @param {string} expression
 * @return {number}
 */
var minOperationsToFlip = function(expression) {
    const n = expression.length;
    const dp = Array.from({ length: n }, () => Array(2).fill(Infinity));
    const stack = [];
    for (let i = 0; i < n; i++) {
        if (expression[i] === '0') {
            dp[i][0] = 0;
            dp[i][1] = 1;
        } else if (expression[i] === '1') {
            dp[i][0] = 1;
            dp[i][1] = 0;
        } else if (expression[i] === '&' || expression[i] === '|') {
            while (stack.length && expression[stack[stack.length - 1]] !== '(') {
                const j = stack.pop();
                const op = expression[j];
                const k = stack.pop();
                const l = stack.pop();
                if (op === '&') {
                    dp[k][0] += Math.min(dp[l][0], dp[l][1]);
                    dp[k][1] += Math.min(dp[l][0], dp[l][1]) + Math.min(dp[j][0], dp[j][1]);
                } else {
                    dp[k][0] += Math.min(dp[l][0], dp[l][1]) + Math.min(dp[j][0], dp[j][1]);
                    dp[k][1] += Math.min(dp[l][0], dp[l][1]);
                }
            }
            stack.push(i);
        } else if (expression[i] === '(') {
            stack.push(i);
        } else if (expression[i] === ')') {
            while (stack.length && expression[stack[stack.length - 1]] !== '(') {
                const j = stack.pop();
                const op = expression[j];
                const k = stack.pop();
                const l = stack.pop();
                if (op === '&') {
                    dp[k][0] += Math.min(dp[l][0], dp[l][1]);
                    dp[k][1] += Math.min(dp[l][0], dp[l][1]) + Math.min(dp[j][0], dp[j][1]);
                } else {
                    dp[k][0] += Math.min(dp[l][0], dp[l][1]) + Math.min(dp[j][0], dp[j][1]);
                    dp[k][1] += Math.min(dp[l][0], dp[l][1]);
                }
            }
            stack  .push(i);
        }
    }
    while (stack.length) {
        const j = stack.pop();
        const op = expression[j];
        const k = stack.pop();
        const l = stack.pop();
        if (op === '&') {
            dp[k][0] += Math.min(dp[l][0], dp[l][1]);
            dp[k][1] += Math.min(dp[l][0], dp[l][1]) + Math.min(dp[j][0], dp[j][1]);
        } else {
            dp[k][0] += Math.min(dp[l][0], dp[l][1]) + Math.min(dp[j][0], dp[j][1]);
            dp[k][1] += Math.min(dp[l][0], dp[l][1]);
        }
    }
    return Math.min(dp[0][0], dp[0][1]);  
};