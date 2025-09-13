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
    let ones = [];
    let twos = [];
    let threes = [];
    let res = '';
    for (let digit of digits) {
        if (digit % 3 === 0) threes.push(digit);
        else if (digit % 3 === 1) ones.push(digit);
        else twos.push(digit);
    }
    threes.sort((a, b) => b - a);
    ones.sort((a, b) => b - a);
    twos.sort((a, b) => b - a);
    while (threes.length > 0 && (ones.length > 1 || twos.length > 1)) {
        res += threes.pop();
        if (ones.length > 1) {
            res += ones.pop();
            res += ones.pop();
        }
        if (twos.length > 1) {
            res += twos.pop();
            res += twos.pop();
        }
    }
    if (threes.length > 0) res += threes.pop();
    else if (ones.length > 0) res += ones.pop();
    else if (twos.length > 0) res += twos.pop();
    return res === '' ? '' : parseInt(res).toString();
};