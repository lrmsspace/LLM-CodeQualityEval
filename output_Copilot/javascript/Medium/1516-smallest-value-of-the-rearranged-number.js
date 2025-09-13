/**https://leetcode.com/problems/smallest-value-of-the-rearranged-number/ */
//You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.
//Return the rearranged number with minimal value.
//Note that the sign of the number does not change after rearranging the digits.
// 
//Example 1:
//Input: num = 310
//Output: 103
//Explanation: The possible arrangements for the digits of 310 are 013, 031, 103, 130, 301, 310. 
//The arrangement with the smallest value that does not contain any leading zeros is 103.
//Example 2:
//Input: num = -7605
//Output: -7650
//Explanation: Some possible arrangements for the digits of -7605 are -7650, -6705, -5076, -0567.
//The arrangement with the smallest value that does not contain any leading zeros is -7650.
// 
//Constraints:
//	-1015 <= num <= 1015
/**
 * @param {number} num
 * @return {number}
 */
var smallestNumber = function(num) {
    let isNegative = num < 0;
    let digits = Math.abs(num).toString().split('').sort((a, b) => isNegative ? b - a : a - b);
    if (!isNegative) {
        for (let i = 1; i < digits.length; i++) {
            if (digits[i] !== '0') {
                [digits[0], digits[i]] = [digits[i], digits[0]];
                break;
            }
        }
    }
    return parseInt((isNegative ? '-' : '') + digits.join(''));    
};