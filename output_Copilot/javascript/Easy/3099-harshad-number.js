/*
 An integer divisible by the sum of its digits is said to be a Harshad number. You are given an integer x. Return the sum of the digits of x if x is a Harshad number, otherwise, return -1.
 Example 1:
 Input: x = 18
 Output: 9
 Explanation:
 The sum of digits of x is 9. 18 is divisible by 9. So 18 is a Harshad number and the answer is 9.
 Example 2:
 Input: x = 23
 Output: -1
 Explanation:
 The sum of digits of x is 5. 23 is not divisible by 5. So 23 is not a Harshad number and the answer is -1.
 Constraints:
 1 <= x <= 100
*/

/**
 * @param {number} x
 * @return {number}
 */
var sumOfTheDigitsOfHarshadNumber = function(x) {
    // Function to calculate the sum of digits of a number
    const sumOfDigits = (num) => {
        return num.toString().split('').reduce((sum, digit) => sum + parseInt(digit), 0);
    };

    // Calculate the sum of digits of x
    const digitSum = sumOfDigits(x);

    // Check if x is divisible by the sum of its digits
    if (x % digitSum === 0) {
        return digitSum; // Return the sum of digits if x is a Harshad number
    } else {
        return -1; // Return -1 if x is not a Harshad number
    }
    
};