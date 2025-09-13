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
    let count = 0;
    for (let i = 1; i <= n; i *= 10) {
        let div = i * 10, mod = n % div;
        count += Math.floor((n / div) % 10) * i + Math.min(mod + 1, i) - i;
    }
    return count;
    
};