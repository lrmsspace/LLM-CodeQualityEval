/**https://leetcode.com/problems/multiply-strings/ */
//Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
// 
//Example 1:
//Input: num1 = "2", num2 = "3"
//Output: "6"
//Example 2:
//Input: num1 = "123", num2 = "456"
//Output: "56088"
// 
//Constraints:
//	1 <= num1.length, num2.length <= 200
//	num1 and num2 consist of digits only.
//	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function(num1, num2) {
    let result = Array(num1.length + num2.length).fill(0);
    
    for(let i = num1.length - 1; i >= 0; i--) {
        for(let j = num2.length - 1; j >= 0; j--) {
            let product = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1];
            result[i + j + 1] = product % 10;
            result[i + j] += Math.floor(product / 10);
        }
    }
    
    let start = 0;
    while(result[start] === 0) start++;
    
    let res = '';
    for(let i = start; i < result.length; i++) res += result[i];
    
    return res || '0';
    
};