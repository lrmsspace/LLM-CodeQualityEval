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
    // Sort the digits in descending order
    digits.sort((a, b) => b - a);
    
    let sum = 0;
    let hasTwo = false;
    let hasThree = false;
    
    // Calculate the sum and check if it's divisible by 3
    for (let digit of digits) {
        sum += digit;
        
        if (digit % 3 === 0) {
            hasThree = true;
        } else if (digit % 3 === 2) {
            hasTwo = true;
        }
    }
    
    if (!hasThree) {
        return "";
    }
    
    let result = "";
    
    // Add the largest possible multiple of 3 to the result
    let remainder = sum % 3;
    if (remainder === 1) {
        if (hasTwo) {
            result += "2";
            hasTwo = false;
        } else {
            result += "1";
        }
    } else if (remainder === 2) {
        result += "1";
    }
    
    // Add the remaining digits in descending order
    for (let digit of digits) {
        if (digit % 3 === 0 && hasThree) {
            result += digit;
            hasThree = false;
        } else if (digit % 3 === 1 && hasTwo) {
            result += digit;
            hasTwo = false;
        }
    }
    
    return result;
    
};