/**https://leetcode.com/problems/add-strings/ */
//Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
//You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
// 
//Example 1:
//Input: num1 = "11", num2 = "123"
//Output: "134"
//Example 2:
//Input: num1 = "456", num2 = "77"
//Output: "533"
//Example 3:
//Input: num1 = "0", num2 = "0"
//Output: "0"
// 
//Constraints:
//	1 <= num1.length, num2.length <= 104
//	num1 and num2 consist of only digits.
//	num1 and num2 don't have any leading zeros except for the zero itself.
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    let carry = 0;
    let result = '';
    let i = num1.length - 1;
    let j = num2.length - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        const digit1 = i >= 0 ? parseInt(num1[i--]) : 0;
        const digit2 = j >= 0 ? parseInt(num2[j--]) : 0;
        const sum = digit1 + digit2 + carry;
        result = (sum % 10) + result;
        carry = Math.floor(sum / 10);
    }

    return result;    
};