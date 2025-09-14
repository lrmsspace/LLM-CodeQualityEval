/**https://leetcode.com/problems/find-the-closest-palindrome/ */
//Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
//The closest is defined as the absolute difference minimized between two integers.
// 
//Example 1:
//Input: n = "123"
//Output: "121"
//Example 2:
//Input: n = "1"
//Output: "0"
//Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
// 
//Constraints:
//	1 <= n.length <= 18
//	n consists of only digits.
//	n does not have leading zeros.
//	n is representing an integer in the range [1, 1018 - 1].
/**
 * @param {string} n
 * @return {string}
 */
var nearestPalindromic = function(n) {
    let num = parseInt(n);
    let lower = Math.floor(num / 10) * 10 + (num % 10) - 1;
    let higher = Math.floor(num / 10) * 10 + (num % 10) + 1;
    if (lower < 0) lower = 0;
    while (lower.toString().length < n.length) lower = lower * 10 + Math.floor(lower / 10) % 10;
    while (higher.toString().length < n.length) higher = higher * 10 + Math.floor(higher / 10) % 10;
    if (num - lower <= higher - num) return lower.toString();
    else return higher.toString();
};