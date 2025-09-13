/**https://leetcode.com/problems/base-7/ */
//Given an integer num, return a string of its base 7 representation.
// 
//Example 1:
//Input: num = 100
//Output: "202"
//Example 2:
//Input: num = -7
//Output: "-10"
// 
//Constraints:
//	-107 <= num <= 107
/**
 * @param {number} num
 * @return {string}
 */
var convertToBase7 = function(num) {
    if (num === 0) return '0';
    let result = '';
    let negative = num < 0;
    num = Math.abs(num);
    
    while (num > 0) {
        result = (num % 7) + result;
        num = Math.floor(num / 7);
    }
    
    return negative ? '-' + result : result;    
};