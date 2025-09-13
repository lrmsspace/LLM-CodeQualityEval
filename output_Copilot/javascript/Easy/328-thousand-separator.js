/**https://leetcode.com/problems/thousand-separator/ */
//Given an integer n, add a dot (".") as the thousands separator and return it in string format.
// 
//Example 1:
//Input: n = 987
//Output: "987"
//Example 2:
//Input: n = 1234
//Output: "1.234"
// 
//Constraints:
//	0 <= n <= 231 - 1
/**
 * @param {number} n
 * @return {string}
 */
var thousandSeparator = function(n) {
    let str = n.toString();
    let result = '';
    for (let i = str.length - 1; i >= 0; i--) {
        result = str[i] + result;
        if ((str.length - i) % 3 === 0 && i !== 0) {
            result = '.' + result;
        }
    }
    return result;    
};