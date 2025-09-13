/**https://leetcode.com/problems/count-numbers-with-unique-digits/ */
//Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.
// 
//Example 1:
//Input: n = 2
//Output: 91
//Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99
//Example 2:
//Input: n = 0
//Output: 1
// 
//Constraints:
//	0 <= n <= 8
/**
 * @param {number} n
 * @return {number}
 */
var countNumbersWithUniqueDigits = function(n) {
    // Base case: if n is 0, there is only one number with 0 unique digits, which is 1.
    if (n === 0) {
        return 1;
    }
    
    // Initialize the count of numbers with unique digits and the current digit being considered.
    let count = 10, digit = 9;
    
    // Iterate from 1 to n-1 to consider the next digit.
    for (let i = 1; i < n; i++) {
        // If the current digit is less than or equal to the remaining unique digits,
        // multiply the count by the number of unique digits that can be formed with the current digit.
        if (digit > 0) {
            count *= digit;
            digit--;
        } else {
            // If the current digit is 0, no more unique digits can be formed with it, so break the loop.
            break;
        }
    }
    
    // Return the total count of numbers with unique digits.
    return count;
    
};