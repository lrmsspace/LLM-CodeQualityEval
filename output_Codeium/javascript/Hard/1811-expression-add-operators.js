/**https://leetcode.com/problems/expression-add-operators/ */
//Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.
//Note that operands in the returned expressions should not contain leading zeros.
// 
//Example 1:
//Input: num = "123", target = 6
//Output: ["1*2*3","1+2+3"]
//Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
//Example 2:
//Input: num = "232", target = 8
//Output: ["2*3+2","2+3*2"]
//Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
//Example 3:
//Input: num = "3456237490", target = 9191
//Output: []
//Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
// 
//Constraints:
//	1 <= num.length <= 10
//	num consists of only digits.
//	-231 <= target <= 231 - 1
/**
 * @param {string} num
 * @param {number} target
 * @return {string[]}
 */
var addOperators = function(num, target) {
    const result = [];
    const dfs = (index, prev, curr, value, multiplier) => {
        if (index === num.length) {
            if (value === target) {
                result.push(curr);
            }
            return;
        }
        for (let i = index; i < num.length; i++) {
            if (i !== index && num[index] === '0') break;
            const n = parseInt(num.substring(index, i + 1));
            if (index === 0) {
                dfs(i + 1, 0, curr + n, n, n);
            } else {
                dfs(i + 1, prev, curr + '+' + n, value + n, n);
                dfs(i + 1, prev, curr + '-' + n, value - n, -n);
                dfs(i + 1, prev, curr + '*' + n, value - prev + prev * n, prev * n);
            }
        }
    };
    dfs(0, 0, '', 0, 0);
    return result;
};