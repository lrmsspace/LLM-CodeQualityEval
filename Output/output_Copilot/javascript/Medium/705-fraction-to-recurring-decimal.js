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
    if (numerator === 0) return "0";
    let res = "";
    if ((numerator < 0) ^ (denominator < 0)) res += "-";
    numerator = Math.abs(numerator);
    denominator = Math.abs(denominator);
    res += Math.floor(numerator / denominator);
    numerator %= denominator;
    if (numerator === 0) return res;
    res += ".";
    const map = new Map();
    while (numerator !== 0) {
        if (map.has(numerator)) {
            const index = map.get(numerator);
            res = res.slice(0, index) + "(" + res.slice(index) + ")";
            break;
        }
        map.set(numerator, res.length);
        numerator *= 10;
        res += Math.floor(numerator / denominator);
        numerator %= denominator;
    }
    return res;    
};