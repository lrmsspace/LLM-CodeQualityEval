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
    
    for (let num = l; num <= r; num++) {
        let digits = [];
        let sum = 0;
        let product = 1;
        
        while (num > 0) {
            let digit = num % 10;
            digits.push(digit);
            sum += digit;
            product *= digit;
            num = Math.floor(num / 10);
        }
        
        if (digits.length === 2 && product % sum === 0) {
            count++;
        }
    }
    
    return count;
    
};