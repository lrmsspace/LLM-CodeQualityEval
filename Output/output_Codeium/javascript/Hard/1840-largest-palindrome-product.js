/**https://leetcode.com/problems/largest-palindrome-product/ */
//Given an integer n, return the largest palindromic integer that can be represented as the product of two n-digits integers. Since the answer can be very large, return it modulo 1337.
// 
//Example 1:
//Input: n = 2
//Output: 987
//Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
//Example 2:
//Input: n = 1
//Output: 9
// 
//Constraints:
//	1 <= n <= 8
/**
 * @param {number} n
 * @return {number}
 */
var largestPalindrome = function(n) {
    let max = Math.pow(10, n) - 1;
    for (let i = max; i > 0; i--) {
        let reverse = parseInt(i.toString().split('').reverse().join(''));
        if (i * max >= reverse && i * max % 1337 === reverse % 1337) return i * max % 1337;
    }
    return 0;
};