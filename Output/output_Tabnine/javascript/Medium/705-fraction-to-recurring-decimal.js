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
    // Handle negative numbers
    let isNegative = (numerator < 0) ^ (denominator < 0);
    numerator = Math.abs(numerator);
    denominator = Math.abs(denominator);
    
    // Convert numerator and denominator to strings
    let numeratorStr = numerator.toString();
    let denominatorStr = denominator.toString();
    
    // Initialize variables
    let result = '';
    let remainder = '';
    let fraction = '';
    
    // Handle integer part
    let integerPart = Math.floor(numerator / denominator);
    result += integerPart.toString();
    
    // Handle fractional part
    numerator %= denominator;
    if (numerator === 0) return result;
    result += '.';
    
    // Store remainders and fractions
    let remainders = new Map();
    
    while (numerator > 0 &&!remainders.has(numerator)) {
        remainders.set(numerator, fraction.length);
        numerator *= 10;
        fraction += numeratorStr[numerator / denominator | 0];
        numerator %= denominator;
    }
    
    if (remainders.has(numerator)) {
        let index = remainders.get(numerator);
        result += fraction.slice(0, index) + '(' + fraction.slice(index) + ')';
    } else {
        result += fraction;
    }
    
    return isNegative? '-' + result : result;
    
};