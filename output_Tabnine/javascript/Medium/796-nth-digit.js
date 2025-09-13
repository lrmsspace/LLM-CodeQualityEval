/**https://leetcode.com/problems/nth-digit/ */
//Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
// 
//Example 1:
//Input: n = 3
//Output: 3
//Example 2:
//Input: n = 11
//Output: 0
//Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
// 
//Constraints:
//	1 <= n <= 231 - 1
/**
 * @param {number} n
 * @return {number}
 */
var findNthDigit = function(n) {
    // Helper function to calculate the number of digits in the n-th number
    function numDigits(n) {
        let digits = 1;
        while (n >= 10 ** digits) {
            n /= 10;
            digits++;
        }
        return digits;
    }
    
    // Helper function to calculate the position of the nth digit in the n-th number
    function digitPosition(n, digits) {
        return Math.floor((n - 1) % (10 ** digits)) + 1;
    }
    
    // Calculate the number of digits in the n-th number
    let digits = numDigits(n);
    
    // Calculate the position of the nth digit
    let position = digitPosition(n, digits);
    
    // Calculate the value of the nth digit
    let value = Math.floor((n - 1) / (10 ** (digits - 1))) + 1;
    
    // Calculate the position of the nth digit within the current number
    let digitPositionWithinNumber = position % digits;
    
    // If the nth digit is in the last digit of the current number, return it
    if (digitPositionWithinNumber === 0) {
        return value % 10;
    }
    
    // If the nth digit is in the first digit of the next number, return 0
    if (digitPositionWithinNumber === digits) {
        return 0;
    }
    
    // If the nth digit is in the middle of the current number, divide the current number by 10
    // and find the nth digit within the new number
    return findNthDigit(value / 10);
    
};