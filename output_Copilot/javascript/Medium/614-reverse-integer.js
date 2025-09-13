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
    let sign = x < 0 ? -1 : 1; // Determine the sign of x
    let reversed = parseInt(Math.abs(x).toString().split('').reverse().join('')) * sign; // Reverse the digits and apply the sign
    if (reversed < Math.pow(-2, 31) || reversed > Math.pow(2, 31) - 1) { // Check for overflow
        return 0;
    }
    return reversed;    
};