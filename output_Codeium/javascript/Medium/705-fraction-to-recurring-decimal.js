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
    if (numerator === 0) {
        return '0';
    }
    let result = '';
    if ((numerator > 0) ^ (denominator > 0)) {
        result += '-';
    }
    let n = Math.abs(numerator);
    let d = Math.abs(denominator);
    let intPart = Math.floor(n / d);
    result += intPart.toString();
    if (n % d === 0) {
        return result;
    }
    result += '.';
    let map = {};
    let r = n % d;
    while (r !== 0 && !(r in map)) {
        map[r] = result.length;
        r *= 10;
        result += Math.floor(r / d);
        r %= d;
    }
    if (r !== 0) {
        let index = map[r];
        result = result.substring(0, index) + '(' + result.substring(index) + ')';
    }
    return result;
};