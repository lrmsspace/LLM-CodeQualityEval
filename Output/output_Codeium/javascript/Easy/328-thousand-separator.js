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
    return n.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ".");  
};