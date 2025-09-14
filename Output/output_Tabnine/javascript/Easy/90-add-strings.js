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
    let len1 = num1.length, len2 = num2.length;
    let carry = 0, result = '';
    
    while (len1 > 0 || len2 > 0 || carry > 0) {
        let digit1 = len1 > 0? parseInt(num1[--len1]) : 0;
        let digit2 = len2 > 0? parseInt(num2[--len2]) : 0;
        
        let sum = carry + digit1 + digit2;
        carry = Math.floor(sum / 10);
        result = (sum % 10) + result;
    }
    
    return result;
    
};