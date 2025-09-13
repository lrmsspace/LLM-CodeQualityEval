/**https://leetcode.com/problems/fraction-to-recurring-decimal/ */
//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//If the fractional part is repeating, enclose the repeating part in parentheses.
//If multiple answers are possible, return any of them.
//It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
// 
//Example 1:
//Input: numerator = 1, denominator = 2
//Output: "0.5"
//Example 2:
//Input: numerator = 2, denominator = 1
//Output: "2"
//Example 3:
//Input: numerator = 4, denominator = 333
//Output: "0.(012)"
// 
//Constraints:
//	-231 <= numerator, denominator <= 231 - 1
//	denominator != 0
/**
 * @param {number} numerator
 * @param {number} denominator
 * @return {string}
 */
var fractionToDecimal = function(numerator, denominator) {
    let sign = (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0) ? "-" : "";
    let n = Math.abs(numerator);
    let d = Math.abs(denominator);
    let integer = Math.floor(n / d);
    let fraction = "";
    let remainder = n % d;
    let map = new Map();
    while (remainder !== 0) {
        if (map.has(remainder)) {
            let index = map.get(remainder);
            fraction = fraction.slice(0, index) + "(" + fraction.slice(index) + ")";
            break;
        }
    }
    map.set(remainder, fraction.length);
    while (remainder !== 0) {
        remainder *= 10;
        fraction += Math.floor(remainder / d);
        remainder = remainder % d;
    }
    return sign + integer + (fraction.length > 0 ? "." + fraction : "");

};