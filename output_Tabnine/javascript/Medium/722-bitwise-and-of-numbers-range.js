/**https://leetcode.com/problems/bitwise-and-of-numbers-range/ */
//Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
// 
//Example 1:
//Input: left = 5, right = 7
//Output: 4
//Example 2:
//Input: left = 0, right = 0
//Output: 0
//Example 3:
//Input: left = 1, right = 2147483647
//Output: 0
// 
//Constraints:
//	0 <= left <= right <= 231 - 1
/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var rangeBitwiseAnd = function(left, right) {
    // iterate through the bits from right to left
    for (let i = 31; i >= 0; i--) {
        // check if the current bit is set in both left and right
        if ((left >> i) & 1 && (right >> i) & 1) {
            // if both bits are set, AND them with the result
            left &= right;
        } else {
            // if the current bit is not set in both left and right, AND it with 0
            left &= ~(1 << i);
            // stop further iterations
            break;
        }
    }
    
    return left;
    
};