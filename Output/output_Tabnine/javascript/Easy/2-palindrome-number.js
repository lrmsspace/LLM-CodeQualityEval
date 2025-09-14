/**https://leetcode.com/problems/palindrome-number/ */
//Given an integer x, return true if x is a palindrome, and false otherwise.
// 
//Example 1:
//Input: x = 121
//Output: true
//Explanation: 121 reads as 121 from left to right and from right to left.
//Example 2:
//Input: x = -121
//Output: false
//Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//Example 3:
//Input: x = 10
//Output: false
//Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// 
//Constraints:
//	-231 <= x <= 231 - 1
// 
//Follow up: Could you solve it without converting the integer to a string?
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    // Handle negative numbers
    if (x < 0) return false;
    
    // Handle single-digit numbers
    if (x < 10) return true;
    
    // Handle numbers with more than 10 digits
    let div = 10;
    let mod = 1;
    while (x / div >= 1) {
        mod = x % div;
        x = (x - mod) / div;
        div *= 100;
    }
    
    // Compare the first half of the number with the second half
    while (x >= 10) {
        let firstDigit = x % 10;
        let secondDigit = mod % 10;
        if (firstDigit!== secondDigit) return false;
        x = (x - firstDigit) / 10;
        mod = (mod - secondDigit) / 10;
    }
    
    return true;
    
};