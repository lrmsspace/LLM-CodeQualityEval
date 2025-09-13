/**https://leetcode.com/problems/number-of-digit-one/ */
//Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
// 
//Example 1:
//Input: n = 13
//Output: 6
//Example 2:
//Input: n = 0
//Output: 0
// 
//Constraints:
//	0 <= n <= 109
/**
 * @param {number} n
 * @return {number}
 */
var countDigitOne = function(n) {
    var count = 0;
    var digit = 1;
    var high = Math.floor(n / 10);
    var cur = n % 10;
    var low = n % 10;
    while (high !== 0 || cur !== 0) {
        if (cur === 0) {
            count += high * digit;
        } else if (cur === 1) {
            count += high * digit + low + 1;
        } else {
            count += (high + 1) * digit;
        }
        digit *= 10;
        n = Math.floor(n / 10);
        high = Math.floor(n / 10);
        cur =n % 10;
    }
    return count;
};