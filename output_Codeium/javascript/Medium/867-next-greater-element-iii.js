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
    let s = n.toString().split('');
    let i = s.length - 2;
    while (i >= 0 && s[i] >= s[i + 1]) i--;
    if (i < 0) return -1;
    let j = s.length - 1;
    while (s[j] <= s[i]) j--;
    [s[i], s[j]] = [s[j], s[i]];
    let result = parseInt(s.slice(0, i + 1).concat(s.slice(i + 1).reverse()).join(''), 10);
    return result > 2 ** 31 - 1 ? -1 : result;

};