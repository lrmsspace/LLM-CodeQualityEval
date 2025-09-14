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
    const thousands = Math.floor(n / 1000);
    const rest = n % 1000;
    
    return rest? `${thousandSeparator(rest)}.${String(thousands).padStart(3, '0')}` : String(thousands).padStart(3, '0');
    
};