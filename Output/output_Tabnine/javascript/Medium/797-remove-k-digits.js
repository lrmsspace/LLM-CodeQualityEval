/**https://leetcode.com/problems/remove-k-digits/ */
//Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
// 
//Example 1:
//Input: num = "1432219", k = 3
//Output: "1219"
//Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
//Example 2:
//Input: num = "10200", k = 1
//Output: "200"
//Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
//Example 3:
//Input: num = "10", k = 2
//Output: "0"
//Explanation: Remove all the digits from the number and it is left with nothing which is 0.
// 
//Constraints:
//	1 <= k <= num.length <= 105
//	num consists of only digits.
//	num does not have any leading zeros except for the zero itself.
/**
 * @param {string} num
 * @param {number} k
 * @return {string}
 */
var removeKdigits = function(num, k) {
    // Convert string to array for easier manipulation
    const digits = Array.from(num);
    
    // Initialize a stack to keep track of the digits
    const stack = [];
    
    // Iterate through the digits
    for (let digit of digits) {
        // While the stack is not empty and the digit is smaller than the top of the stack
        // and the number of remaining digits to remove is greater than 0
        while (stack.length > 0 && stack[stack.length - 1] > digit && k > 0) {
            stack.pop();
            k--;
        }
        
        // Push the current digit onto the stack
        stack.push(digit);
    }
    
    // If there are still digits to remove, pop them from the stack
    while (k > 0) {
        stack.pop();
        k--;
    }
    
    // Convert the stack back to a string and remove leading zeros
    const result = stack.join('');
    return result.startsWith('0')? '0' : result;
    
};