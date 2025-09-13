/**https://leetcode.com/problems/next-greater-element-iii/ */
//Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
//Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
// 
//Example 1:
//Input: n = 12
//Output: 21
//Example 2:
//Input: n = 21
//Output: -1
// 
//Constraints:
//	1 <= n <= 231 - 1
/**
 * @param {number} n
 * @return {number}
 */
var nextGreaterElement = function(n) {
    const digits = String(n).split('').map(Number);
    let i = digits.length - 1;
    while (i > 0 && digits[i] <= digits[i - 1]) {
        i--;
    }
    if (i === 0) {
        return -1;
    }
    let j = digits.length - 1;
    while (digits[j] <= digits[i - 1]) {
        j--;
    }
    [digits[i - 1], digits[j]] = [digits[j], digits[i - 1]];
    digits.splice(i, digits.length - i).reverse();
    const result = parseInt(digits.join(''), 10);
    return result > Math.pow(2, 31) - 1? -1 : result;
    
};