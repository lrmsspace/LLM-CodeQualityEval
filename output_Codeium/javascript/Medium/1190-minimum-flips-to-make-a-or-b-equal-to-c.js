/**https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/ */
//Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
//Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.
// 
//Example 1:
//Input: a = 2, b = 6, c = 5
//Output: 3
//Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
//Example 2:
//Input: a = 4, b = 2, c = 7
//Output: 1
//Example 3:
//Input: a = 1, b = 2, c = 3
//Output: 0
// 
//Constraints:
//	1 <= a <= 10^9
//	1 <= b <= 10^9
//	1 <= c <= 10^9
/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var minFlips = function(a, b, c) {
    let acount = 0
    let bcount = 0
    let x = a ^ c
    let y = b ^ c
    while (x) {
        acount += x & 1
        x >>>= 1
    }
    while (y) {
        bcount += y & 1
        y >>>= 1
    }
    return acount + bcount
};