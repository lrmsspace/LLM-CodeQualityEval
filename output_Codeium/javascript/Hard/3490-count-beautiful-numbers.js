/*
 You are given two positive integers, l and r. A positive integer is called beautiful if the product of its digits is divisible by the sum of its digits.
 Return the count of beautiful numbers between l and r, inclusive.
 Example 1:
 Input: l = 10, r = 20
 Output: 2
 Explanation:
 The beautiful numbers in the range are 10 and 20.
 Example 2:
 Input: l = 1, r = 15
 Output: 10
 Explanation:
 The beautiful numbers in the range are 1, 2, 3, 4, 5, 6, 7, 8, 9, and 10.
 Constraints:
 1 <= l <= r < 109
*/

/**
 * @param {number} l
 * @param {number} r
 * @return {number}
 */
var beautifulNumbers = function(l, r) {
    let count = 0;
    for (let i = l; i <= r; ++i) {
        let product = 1;
        let sum = 0;
        let number = i;
        while (number > 0) {
            let digit = number % 10;
            product *= digit;
            sum += digit;
            number = Math.floor(number / 10);
        }
        if (product % sum === 0) {
            ++count;
        }
    }
    return count;
};