/**https://leetcode.com/problems/reverse-integer/ */
//Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
//Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
// 
//Example 1:
//Input: x = 123
//Output: 321
//Example 2:
//Input: x = -123
//Output: -321
//Example 3:
//Input: x = 120
//Output: 21
// 
//Constraints:
//	-231 <= x <= 231 - 1
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let isNegative = x < 0;
    let result = 0;
    x = Math.abs(x);
    while (x > 0) {
        result = result * 10 + x % 10;
        x = Math.floor(x / 10);
    }
    if (result > Math.pow(2, 31) - 1) {
        return 0;
    }
    return isNegative ? -result : result;
};