/**https://leetcode.com/problems/add-binary/ */
//Given two binary strings a and b, return their sum as a binary string.
// 
//Example 1:
//Input: a = "11", b = "1"
//Output: "100"
//Example 2:
//Input: a = "1010", b = "1011"
//Output: "10101"
// 
//Constraints:
//	1 <= a.length, b.length <= 104
//	a and b consist only of '0' or '1' characters.
//	Each string does not contain leading zeros except for the zero itself.
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let maxLength = Math.max(a.length, b.length);
    let carry = 0;
    let result = '';
    
    for (let i = 0; i < maxLength; i++) {
        let digitA = a[a.length - 1 - i] || '0';
        let digitB = b[b.length - 1 - i] || '0';
        
        let sum = parseInt(digitA) + parseInt(digitB) + carry;
        
        carry = Math.floor(sum / 2);
        result = (sum % 2) + result;
    }
    
    if (carry > 0) {
        result = carry + result;
    }
    
    return result;
    
};