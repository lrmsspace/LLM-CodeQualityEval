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
    var result = "";
    var count = 0;
    while(n > 0){
        var digit = n % 10;
        result = digit + result;
        count++;
        if(count % 3 === 0 && n > 9){
            result = "." + result;
        }
        n = Math.floor(n / 10);
    }
    return result;

};