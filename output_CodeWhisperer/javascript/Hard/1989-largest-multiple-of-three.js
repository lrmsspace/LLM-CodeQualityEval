/**https://leetcode.com/problems/largest-multiple-of-three/ */
//Given an array of digits digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order. If there is no answer return an empty string.
//Since the answer may not fit in an integer data type, return the answer as a string. Note that the returning answer must not contain unnecessary leading zeros.
// 
//Example 1:
//Input: digits = [8,1,9]
//Output: "981"
//Example 2:
//Input: digits = [8,6,7,1,0]
//Output: "8760"
//Example 3:
//Input: digits = [1]
//Output: ""
// 
//Constraints:
//	1 <= digits.length <= 104
//	0 <= digits[i] <= 9
/**
 * @param {number[]} digits
 * @return {string}
 */
var largestMultipleOfThree = function(digits) {
    let sum = 0;
    let count = [0, 0, 0];
    for (let i = 0; i < digits.length; i++) {
        sum += digits[i];
        count[digits[i] % 3]++;
    }
    let remove = (sum % 3 === 1) ? (count[1] > 0 ? 1 : 2) : (sum % 3 === 2) ? (count[2] > 0 ? 2 : 1) : 0;
    let result = [];
    for (let i = 0; i < digits.length; i++) {
        if (remove > 0 && digits[i] % 3 === remove - 1) {
            remove--;
        } else {
            result.push(digits[i]);
        }
    }
    if (result.length === 0) return "";
    result.sort((a, b) => b - a);
    if (result[result.length - 1] === 0) return "0";
    return result.join("");
};